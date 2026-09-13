# myElectron Solar IoT: Open-Source ESP32 Solar-Powered IoT Development Platform

*Integrated Solar Charger, Battery Power Management, and LoRaWAN / Cellular Expansion*

The **myElectron Solar IoT** is a compact, stand-alone development platform designed for off-grid and battery-powered IoT nodes. By integrating an ESP32 microcontroller, solar charging circuit, intelligent power management, and versatile expansion interfaces onto a single board, it eliminates the need to design custom power subsystems from scratch. Field-proven with **over 8,000 active station deployments nationwide**, it is the ideal foundation for environmental monitoring, smart agriculture, remote telemetry, and custom DIY projects.

---

## 🛠️ On-Board Hardware Specifications

* **Microcontroller:** ESP32-WROOM-32
* **Solar Battery Charger:** CN3065 Solar Lithium Battery Management IC
* **Power Boost:** Integrated 5V Step-Up Power Module
* **Battery Holder:** On-board 18650 Li-ion Battery Holder
* **Duty Cycle Controller:** Dedicated ATtiny13A Power Cycling Controller
* **Sensors & Indicators:** On-board Tilt Switch and Status LED
* **Controls:** Reset / Programming Switch, Waterproof ON/OFF Rocker Switch
* **Interfaces:** Hardware UART, LoRaWAN / 4G-LTE Expansion Header, External GPIO Connector

---

## 🔌 GPIO & Sensor Interface

Connect external sensors and actuators effortlessly using the onboard expansion header:

`SCL` | `SDA` | `IO34` | `IO35` | `IO14` | `IO27` | `3.3V` | `5V` | `GND`

---

## ☀️ Designed for Solar-Powered IoT

Skip complex power architecture design. The board provides a complete end-to-end power flow out of the box:

`Solar Panel` ➔ `Solar Charger` ➔ `18650 Battery` ➔ `Power Management` ➔ `ESP32`

---

## ⚡ Hardware-Based Automatic Power Cycling

The key highlight of the board is its **ATtiny13A-based power cycling controller**, which enables hard power cycling to maximize battery longevity beyond standard software sleep modes:

* **Duty Cycle Operation:** `ON (1 min for reading/transmission)` ➔ `OFF (4 mins power cut)`
* **Bypass Feature:** Includes a manual/software bypass for continuous power operation or native ESP32 Deep Sleep modes.
* **Ideal Applications:** Periodic sensor logging, remote telemetry nodes, outdoor weather stations, and off-grid LoRaWAN sensors.

---

## 📡 LoRaWAN / 4G-LTE Modular Expansion

The board includes dedicated headers for external wireless communication modules, allowing flexible network architecture:

* **Solar IoT Controller + LoRaWAN**
* **Solar IoT Controller + 4G-LTE**

Swap communication protocols as project needs evolve without altering the core power management or main board layout.

---

## 🌧️ IP65 Enclosure Ready

Engineered specifically for outdoor deployment, the board seamlessly integrates into standard IP65 weatherproof enclosures. Enclosures feature dedicated mounting points and knockouts for:

* Cable glands
* Waterproof power switches
* External SMA antenna connectors

---

## 🎯 Applications & Use Cases

* Smart Agriculture & Irrigation Control
* Outdoor Environmental & Air Quality (AQI) Monitoring
* Remote Industrial Telemetry & Weather Stations
* Off-Grid LoRaWAN / Cellular Sensor Nodes
* Embedded Systems Development & Rapid Prototyping

---

## 🛒 Recommended myElectron Ecosystem

Pair the Solar IoT Controller with fully compatible accessories from the myElectron lineup:

* **Power:** 5.5V 2W Solar Panel with Mounting Bracket, 18650 Rechargeable Battery
* **Wireless:** RBS76 NBTC-Certified LoRaWAN Module, 920MHz 5dBi Antenna, SMA/IPEX RF Accessories
* **Sensors (Includes ready-to-use firmware with Web & Mobile Dashboard support):**
* Outdoor BME280 Sensor Probe
* PMS7003 + BME280 AQI Fusion Sensor Probe


* **Industrial Sensors:** MODBUS RS485 Soil Moisture Probe
* **Hardware:** IP65 Weatherproof Enclosure, Solar Radiation Shield (Louvered)
