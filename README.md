# myElectyron Solar IoT : Opensource ESP32 Solar-Powered IoT Development Platform
# ชุดพัฒนา Solar IoT ที่รวม Solar Charger + Battery Power Management พร้อม LoRaWAN
# Solar Iot Esp32 Development platform bundled with Solar Charger + Battery Power Management and Lorawan
# ------------------------------------------------------------------------------------------------------
# 
Build your own solar-powered IoT node with a compact, integrated power-management controller.
myElectron Solar IoT เป็น development platform สำหรับสร้าง stand-alone / remote IoT node ที่ทำงานด้วยแบตเตอรี่และพลังงานแสงอาทิตย์ โดยรวม ESP32, solar charger, power management และ interface สำหรับ LoRaWAN / 4G-LTE / port ต่อขยาย I/O และ sensors ไว้ในบอร์ดนนต.
มีการใช้งานจริงในภาคสนามมาแล้วมากกว่า 8,000 สถานีทั่วประเทศ เหมาะสำหรับงาน IoT, AQI/Environmental Monitoring, Agriculture, Remote Sensing, LoRaWAN, Telemetry และ DIY Project

 Integrated Hardware
ตัวบอร์ดประกอบด้วย:
● ESP32-WROOM-32
● CN3065 Solar Battery Charger
● 5V Step-Up Power Module
● 18650 Battery Holder
● ATtiny13A Power Cycling Controller
● Tilt Switch
● Status LED
● On-board Reset / Programming Switch
● ON/OFF Waterproof Rocker Switch
● UART Interface
● Expansion Interface สำหรับ LoRaWAN / 4G-LTE module (available soon)
● External GPIO connector

GPIO / Sensor Interface
รองรับการต่ออุปกรณ์ภายนอกผ่าน connector:
SCL / SDA / IO34 / IO35 / IO14 / IO27 / 3.3V / 5V / GND
สามารถนำไปต่อกับ Sensor, Actuator หรือ external I/O ได้ตามลักษณะของ application


# ☀️ Designed for Solar-Powered IoT
# ตัวบอร์ดถูกออกแบบมาเพื่อสร้าง IoT node ที่สามารถทำงานจาก
Solar Panel → Solar Charger → 18650 Battery → Power Management → ESP32
โดยไม่จำเป็นต้องออกแบบ power subsystem ใหม่ตั้งแต่ต้น
# ⚡ Automatic Power Cycling
# จุดเด่นของบอร์ดคือ ATtiny13A-based power cycling controller
สามารถกำหนดการทำงานแบบเป็นรอบเพื่อลดการใช้พลังงานของอุปกรณ์ เช่น:
ON → 1 minute → Sensor Reading
OFF → 4 minutes
พร้อม Bypass function สำหรับกรณีที่ต้องการให้ระบบทำงานต่อเนื่องหรือใช้กับ ESP32 Deepsleep
เหมาะกับ application ที่ต้องการประหยัดพลังงานสูงสุด เช่น:
● Periodic sensor reading
● Outdoor Environmental monitoring station
● Remote telemetry
● Solar-powered LoRaWAN node
● Battery-powered IoT project

# LoRaWAN / 4G-LTE Expansion
ตัวบอร์ดเตรียม interface สำหรับเพิ่ม communication module ภายนอก
รองรับการออกแบบระบบในลักษณะ:
Solar IoT Controller + LoRaWAN
หรือ
Solar IoT Controller + 4G-LTE
ทำให้สามารถเลือก communication technology ให้เหมาะกับ application โดยไม่ต้องเปลี่ยน architecture หลักของ power/controller board

️# IP65 Enclosure Ready
สามารถติดตั้ง Controller Board ภายใน IP65 enclosure เพื่อพัฒนาเป็น outdoor IoT node
ตัว enclosure มีช่องสำหรับ:
● Cable gland
● Power switch
● SMA antenna connector
พร้อมใช้งานสำหรับการพัฒนา node ที่ต้องติดตั้งภายนอกอาคารหรือในพื้นที่ remote


# Build Your Own IoT Node
สามารถนำไปประยุกต์ใช้กับ:
● Agricultural monitoring
● ️ Environmental monitoring
● LoRaWAN sensor node
● ️ Remote telemetry
● ️ Temperature / humidity / pressure monitoring
● Industrial IoT project
● Solar-powered embedded systems
● IoT development & experimentation

 Recommended Ecosystem
*****************************
Solar IoT Controller สามารถใช้งานร่วมกับอุปกรณ์ในร้าน MyElectron เช่น:
● 5.5V 2W Solar Panel พร้อมขาตั้ง
● 18650 Rechargeable Battery
● RBS76 NBTC Certified LoRaWAN Module
● 920MHz 5dBi LoRa Antenna
● IP65 Enclosure
● Outdoor BME280 Sensor Probe ( มี Firmware พร้อมใช้งานและดูข้อมูลผ่าน web หรือ smartphone ได้ทันที )
● PMS7003+BME280 AQI Fusion Sensor  ( มี Firmware พร้อมใช้งานและดูข้อมูลผ่าน web หรือ smartphone ได้ทันที )
● Soil Moisture Sensor Probe : MODBUS-485
● SMA / IPEX RF Accessories
● ​Solar Radiation Shield (Louver)
 
