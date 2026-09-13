#include <SoftwareSerial.h>

#define PMS_RX  14 // ต่อเข้ากับขา TX ของ PMS7003
#define PMS_TX  -1 // ไม่ใช้ขา TX ของ ESP32 (อ่านค่าอย่างเดียว)
#define PMS_SET 27 // ขา Enable เปิด/ปิดการทำงานโมดูล

SoftwareSerial PMS;

bool readPMS7003(unsigned int &pm01, unsigned int &pm25, unsigned int &pm10) {
  if (!PMS.available()) return false;

  char value;
  char previousValue;
  int index = 0;

  while (PMS.available()) {
    value = PMS.read();

    // ตรวจสอบ Header Frame (0x42, 0x4D)
    if ((index == 0 && value != 0x42) || (index == 1 && value != 0x4D)) {
      break;
    }

    if (index == 4 || index == 6 || index == 8) {
      previousValue = value;
    } else if (index == 5) {
      pm01 = 256 * (unsigned char)previousValue + (unsigned char)value;
    } else if (index == 7) {
      pm25 = 256 * (unsigned char)previousValue + (unsigned char)value;
    } else if (index == 9) {
      pm10 = 256 * (unsigned char)previousValue + (unsigned char)value;
    } else if (index > 15) {
      // ล้างบัฟเฟอร์ส่วนที่เหลือ
      while (PMS.available()) PMS.read();
      return true;
    }
    index++;
  }
  return false;
}

void setup() {
  Serial.begin(115200);

  // เปิดการทำงานของ PMS7003
  pinMode(PMS_SET, OUTPUT);
  digitalWrite(PMS_SET, HIGH);

  PMS.begin(9600, SWSERIAL_8N1, PMS_RX, PMS_TX, false);
  Serial.println("\n--- PMS7003 Sensor Test (RX Only) ---");
}

void loop() {
  unsigned int pm01 = 0, pm25 = 0, pm10 = 0;

  if (readPMS7003(pm01, pm25, pm10)) {
    Serial.printf("PM1.0: %u ug/m3 | PM2.5: %u ug/m3 | PM10: %u ug/m3\n", pm01, pm25, pm10);
  } else {
    Serial.println("Waiting for valid data from PMS7003...");
  }

  delay(2000);
}
