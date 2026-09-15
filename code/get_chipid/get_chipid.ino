#include <WiFi.h>

uint8_t mac[6];

String getChipID() {
  WiFi.macAddress(mac);
  char idBuf[13];
  
  // %02x = บังคับ 2 หลัก เติม 0 ด้านหน้า และเป็นตัวพิมพ์เล็ก (ตรงตาม String(val, HEX) ในโค้ดเดิม)
  sprintf(idBuf, "%02x%02x%02x%02x%02x%02x", 
          mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
          
  return String(idBuf);
}

void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println("\n--- Reading ESP32 Chip ID ---");
  
  String chipId = getChipID();
  Serial.print("ChipID : ");
  Serial.println(chipId);
}

void loop() {
}
