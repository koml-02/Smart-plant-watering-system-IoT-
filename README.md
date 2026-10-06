# 🌱 Smart Plant Watering System

An Arduino UNO-based automatic plant watering system that monitors soil moisture and automatically controls a water pump using a relay module.

The system checks the moisture level of the soil using a soil moisture sensor. When the soil becomes dry, the Arduino activates the water pump. When sufficient moisture is detected, the pump is switched off.

> **Note:** The current version is an Arduino-based automatic watering system. It does not include Wi-Fi, cloud connectivity, or remote monitoring, so it is not an IoT-connected system yet.

---

## 🚀 Features

* Automatic soil moisture monitoring
* Automatic water pump control
* Arduino UNO based
* Soil moisture sensor
* Relay-controlled pump
* Serial Monitor output
* Adjustable moisture threshold
* Pump automatically turns ON when soil is dry
* Pump automatically turns OFF when soil is sufficiently wet

---

## 🛠️ Components Required

| Component                      |    Quantity |
| ------------------------------ | ----------: |
| Arduino UNO                    |           1 |
| Soil Moisture Sensor           |           1 |
| Relay Module                   |           1 |
| DC Water Pump                  |           1 |
| External Power Supply for Pump |           1 |
| Water Tube                     |           1 |
| Jumper Wires                   | As required |
| Breadboard                     |           1 |

---

## 🔌 Circuit Connections

### Soil Moisture Sensor

| Sensor Pin | Arduino UNO |
| ---------- | ----------- |
| VCC        | 5V          |
| GND        | GND         |
| AO         | A1          |

### Relay Module

| Relay Pin | Arduino UNO   |
| --------- | ------------- |
| VCC       | 5V            |
| GND       | GND           |
| IN        | Digital Pin 3 |

The relay used in this project is assumed to be **LOW-triggered**:

* `LOW` → Relay ON → Pump ON
* `HIGH` → Relay OFF → Pump OFF

### Water Pump

The water pump should be powered using an appropriate external power supply through the relay's switching contacts.

**Do not power a larger water pump directly from an Arduino UNO GPIO pin.**

---

## ⚙️ How It Works

The soil moisture sensor produces an analog value that is read by the Arduino through pin `A1`.

The Arduino compares this reading with a predefined threshold:

```cpp
int threshold = 700;
```

The basic logic is:

```text
             Soil Sensor
                  │
                  ▼
            Arduino UNO
                  │
          Read moisture value
                  │
            Compare with
             threshold
                  │
        ┌─────────┴─────────┐
        │                   │
     Dry Soil           Wet Soil
        │                   │
        ▼                   ▼
   Relay ON             Relay OFF
        │                   │
        ▼                   ▼
    Pump ON              Pump OFF
```

The Arduino checks the soil every 2 seconds.

---

## 💻 Software

### Arduino IDE

This project can be programmed using the Arduino IDE.

Official Arduino website:

https://www.arduino.cc/

### Required Libraries

No external Arduino libraries are required for the current version.

The program uses standard Arduino functions such as:

* `analogRead()`
* `digitalWrite()`
* `pinMode()`
* `Serial.begin()`
* `delay()`

---

## 📂 Project Structure

```text
Smart-Plant-Watering/
│
├── SmartPlantWatering.ino
└── README.md
```

---

## 🔧 Moisture Threshold Calibration

The value:

```cpp
int threshold = 700;
```

is only a starting point.

Different soil moisture sensors can produce different readings.

To calibrate the system:

1. Upload the program to the Arduino UNO.
2. Open the Arduino Serial Monitor.
3. Set the baud rate to **9600**.
4. Observe the soil sensor value when the soil is dry.
5. Add water and observe the value when the soil is wet.
6. Choose a threshold between the dry and wet readings.

For example:

```text
Dry soil  → 450
Wet soil  → 850
```

A threshold around:

```cpp
int threshold = 650;
```

could then be tested.

The correct threshold depends on your specific sensor and soil.

---

## 📊 Serial Monitor

The Arduino prints the sensor reading and pump status to the Serial Monitor.

Example:

```text
Smart Plant Watering System
System ready. Insert sensor into soil.
Soil value = 450 -> Dry: PUMP ON
Soil value = 480 -> Dry: PUMP ON
Soil value = 780 -> Wet: PUMP OFF
Soil value = 820 -> Wet: PUMP OFF
```

---

## ▶️ How to Run

### Step 1 — Open Arduino IDE

Install and open Arduino IDE.

### Step 2 — Open the Code

Open:

```text
SmartPlantWatering.ino
```

### Step 3 — Connect Arduino

Connect the Arduino UNO to your computer using a USB cable.

### Step 4 — Select Board

In Arduino IDE, select:

```text
Board: Arduino UNO
```

Select the correct COM/serial port.

### Step 5 — Upload

Click **Upload**.

### Step 6 — Open Serial Monitor

Open the Serial Monitor and set:

```text
Baud Rate: 9600
```

### Step 7 — Test

Place the soil moisture sensor in the soil.

The system should automatically control the pump depending on the moisture reading.

---

## ⚠️ Safety Notes

* Do not connect the water pump directly to an Arduino digital pin.
* Use an appropriate external power supply for the pump.
* Make sure the relay module is compatible with the Arduino.
* Keep water away from the Arduino board and electrical connections.
* Double-check relay wiring before powering the pump.
* The relay logic in this project assumes a **LOW-trigger relay module**.

---

## 🔮 Future Improvements

The project can be upgraded to become a true IoT plant-monitoring system.

Possible improvements include:

* ESP8266 or ESP32 Wi-Fi connectivity
* Mobile application
* Web dashboard
* Remote pump control
* Cloud data storage
* Real-time soil moisture monitoring
* Automatic notifications
* Multiple plant monitoring
* Water tank level monitoring
* DHT11/DHT22 temperature and humidity sensor
* MQTT integration
* Blynk integration

---

## 🎯 Project Goal

The goal of this project is to reduce manual watering by automatically detecting soil moisture and activating a water pump when the plant needs water.

The project demonstrates basic concepts of:

* Arduino programming
* Analog sensor reading
* Digital output control
* Relay operation
* Automation
* Embedded systems
* Soil moisture monitoring

---

## 📜 License

This project is open-source and can be used for educational and personal projects.
