#define SOLAR_ADC_PIN 32
#define BATT_ADC_PIN  33

// ค่า Vref อ้างอิงจากโค้ดเดิม (Default = 1810)
const int VREF = 1810; 

uint32_t readADCAverage(uint8_t pin, int samples = 100) {
  uint32_t total = 0;
  for (int i = 0; i < samples; i++) {
    total += analogRead(pin);
    delay(1);
  }
  return total / samples;
}

void setup() {
  Serial.begin(115200);

  pinMode(SOLAR_ADC_PIN, INPUT);
  pinMode(BATT_ADC_PIN, INPUT);

  Serial.println("\n--- ADC Reading Test (IO32, IO33) ---");
}

void loop() {
  // อ่านค่า Raw ADC แบบสุ่มเฉลี่ย 100 ครั้ง
  uint32_t batt_raw = readADCAverage(BATT_ADC_PIN, 100);
  uint32_t solar_raw = readADCAverage(SOLAR_ADC_PIN, 100);

  // คำนวณเป็นระดับแรงดันไฟฟ้า (V) ตามสูตรเดิม
  float batt_voltage  = ((float)batt_raw  / 4095.0) * 2.0 * 3.3 * (VREF / 1000.0);
  float solar_voltage = ((float)solar_raw / 4095.0) * 2.0 * 3.3 * (VREF / 1000.0);

  Serial.println("----------------------------------------");
  Serial.printf("Battery  (IO33) -> Raw ADC: %4u | Voltage: %.2f V\n", batt_raw, batt_voltage);
  Serial.printf("Solar PV (IO32) -> Raw ADC: %4u | Voltage: %.2f V\n", solar_raw, solar_voltage);

  delay(2000);
}
