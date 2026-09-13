#include  "esp_sleep.h"
#include  "soc/soc.h"
#include  "soc/rtc_cntl_reg.h"



//*****************************************************//
// LoRaWAN RBS76-V2
//*****************************************************//
#include  "config.h"
#define   SERIAL2_RXPIN 16
#define   SERIAL2_TXPIN 17
#define   LoRaSerial    Serial2
uint8_t   AppDataSize = 0;
uint8_t   AppData[64];
char      buff[128];



#define   LED       23
uint8_t   cntTX   = 0;
String    line    = "";
String    text    = "";

uint32_t  totalT  = 0;
#define   uS_TO_S_FACTOR 1000000    /* Conversion factor for micro seconds to seconds */
#define   TIME_TO_SLEEP  30         /* 30 ESP32 will go to sleep (in seconds) */
//-----------------------------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------------------------
void LoRa_GetRet(int t){
    int cnt = 0;
    for(int i=0; i<2; i++){
        text = "";
        cnt = 0;
        while( true ){
            if( LoRaSerial.available() ){    
                char c = LoRaSerial.read();
                if( c == '\n' ){
                    break;
                }else if( c!='\r' ){ text += c; }
            }
            delay(1);
            if( cnt++ > t ){
                text = "TOUT";
                break;
            }
        }
    }
}
//-----------------------------------------------------------------------------------------------------
void LoRa_GetMSG(String MSG, int t){
    int cnt = 0;
    cntTX = 0;
    text = "";
    line = "";
    LoRaSerial.flush();
    while(LoRaSerial.available() > 0) { char c = LoRaSerial.read(); }
    while( true ){
        if( LoRaSerial.available() ){
            char c = LoRaSerial.read();
            if( c == '\n' ){
                if( text.length()>0 ){
                    if( text.indexOf(MSG)>0 || text.indexOf("err")>0 || text.indexOf("tx_ok")>0){
                        line = line + text;
                        break;
                    }else{
                        if( text.indexOf("Tx Send")>0 ){ digitalWrite(LED,false); cntTX += 1; }
                        if( text.indexOf("OnRadioTxDone")>0 ){ digitalWrite(LED,true); }
                        Serial.println(text);
                        text = "";
                        line = line + text;
                        }
                }
            }else if( c!='\r' ){ text += c; }
        }
        delay(1);
        if( cnt++ > t ){
            text = "TOUT";
            line = text;
            break;
        }
    }
}
//-----------------------------------------------------------------------------------------------------
void initLoRa()
{
    Serial.println("Initial LoRaWAN...");
    LoRaSerial.print("mac get_band");
    while(LoRaSerial.available()) LoRaSerial.read();
    
    //LoRaSerial.print("sip factory_reset");
    //LoRa_GetRet(1000);  Serial.println("FACTORY RESET " + text);
    LoRaSerial.print("sip set_log debug");
    LoRa_GetRet(1000);  Serial.println("DEBUG-LOG " + text);
    delay(50);

    LoRaSerial.print("mac set_adr off");
    LoRa_GetRet(1000);  Serial.println("SET ADR-OFF " + text);
    delay(50);
    LoRaSerial.print("mac set_dr 1");
    LoRa_GetRet(1000);  Serial.println("SET DR1 " + text);
    delay(50);
    LoRaSerial.print("mac set_txretry 2");
    LoRa_GetRet(1000);  Serial.println(text);
    delay(50);
    LoRaSerial.print("mac set_tx_confirm on");
    LoRa_GetRet(1000);  Serial.println("SET TX-CNF " + text);
    delay(50);
    LoRaSerial.print("mac set_max_eirp 6");     //---> TX 20dBm
    LoRa_GetRet(1000);  Serial.println("MAX-EIRP 6 " + text);
    delay(50);

    LoRaSerial.print("mac set_nwkskey ");
    LoRaSerial.print(nwskey);
    LoRa_GetRet(1000);  Serial.println(text);
    LoRaSerial.print("mac set_appskey ");
    LoRaSerial.print(appskey);
    LoRa_GetRet(1000);  Serial.println(text);
    delay(100);
    LoRaSerial.print("mac set_deveui ");
    LoRaSerial.print(deveui);
    LoRa_GetRet(1000);  Serial.print("DevEUI: "); Serial.print(deveui); Serial.println(text);
    LoRaSerial.print("mac set_devaddr ");
    LoRaSerial.print(devadr);
    LoRa_GetRet(1000);  Serial.print("DevADDR: ");Serial.print(devadr); Serial.println(text);
    
}
//-----------------------------------------------------------------------------------------------------
void setup()
{
    esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);

    totalT  = millis();

    pinMode(LED, OUTPUT);
    digitalWrite(LED, false);

    Serial.begin(115200);
    LoRaSerial.begin(115200, SERIAL_8N1, SERIAL2_RXPIN, SERIAL2_TXPIN);
    delay(500);

    while(LoRaSerial.available() > 0) { char c = LoRaSerial.read(); Serial.print(c);}
    
    digitalWrite(LED, true);
}
//-----------------------------------------------------------------------------------------------------
void loop()
{
    long  TxTime   = 0;
    long  SendTime = 0;
    
    digitalWrite(LED, false);
    initLoRa();

    LoRaSerial.print("mac join abp");
    LoRa_GetMSG("accepted", 1000);
    Serial.println("Join " + text);
    if( text.indexOf("OUT")>0 ){
        LoRaSerial.print("mac join abp");
        LoRa_GetMSG("accepted", 1000);
        Serial.println("Join " + text);
        if( text.indexOf("OUT")>0 ){
            Serial.println("Join LoRaWAN Network FAIL!");
            Serial.println("SLEEP "+String(TIME_TO_SLEEP)+" sec.");
            esp_deep_sleep_start();
        }
    }

    Serial.println("Sending...");
    AppDataSize = 4;                         //Test Sending Data 01020304
    AppData[0]  = 0x01;
    AppData[1]  = 0x02;
    AppData[2]  = 0x03;
    AppData[3]  = 0x04;
    sprintf(buff, "%02x%02x%02x%02x", AppData[0],AppData[1], AppData[2], AppData[3]);


    TxTime = millis();
    Serial.println(buff);
    LoRaSerial.print("mac tx cnf 9 ");                          // Send with Confirm message
    //LoRaSerial.print("mac tx ucnf 9 ");                       // Send without Confirm message
    LoRaSerial.print(buff);
    LoRa_GetMSG("tx_ok", 20000);


    SendTime = millis() - TxTime;
    Serial.println(line);
    Serial.println("Sending " + String(cntTX) + " time in " + String(SendTime/1000) + "s.");
    digitalWrite(LED, false); delay(100);
    digitalWrite(LED, true);


    while(LoRaSerial.available() > 0) { char c = LoRaSerial.read(); }
    LoRaSerial.print("sip sleep 60 uart_on");                   // Sleep LoRa Module
    LoRa_GetRet(1000);  Serial.println("LoRa SLEEP " + text);
    digitalWrite(LED, true);
    

    totalT = (millis()-totalT)/1000;
    Serial.println("On-Time = "+String(totalT)+" sec.");
    Serial.println("ESP-SLEEP "+String(TIME_TO_SLEEP)+" sec.");
    esp_deep_sleep_start();
    
}
