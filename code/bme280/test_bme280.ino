#include <Wire.h>
#include <BME280I2C.h>

#define I2C_SDA 21
#define I2C_SCL 22

BME280I2C bme;

void setup() {
  Serial.begin(115200);

  // เริ่มใช้งาน I2C
  Wire.begin(I2C_SDA, I2C_SCL);

  Serial.println("\n--- BME280 Sensor Test ---");
  if (!bme.begin()) {
    Serial.println("Could not find BME280 sensor! Check wiring.");
  } else {
    Serial.println("BME280 Initialized Successfully!");
  }
}

void loop() {
  float temp(NAN), humid(NAN), pressure(NAN);
  BME280::TempUnit tempUnit(BME280::TempUnit_Celsius);
  BME280::PresUnit presUnit(BME280::PresUnit_Pa);

  // อ่านค่าจากเซนเซอร์
  bme.read(pressure, temp, humid, tempUnit, presUnit);

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" °C | Humid: ");
  Serial.print(humid);
  Serial.print(" %RH | Pressure: ");
  Serial.print(pressure);
  Serial.println(" Pa");

  delay(2000);
}
