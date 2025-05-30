# Smart Parking System 🚗🅿️

An automated Smart Parking System using **Arduino Uno**, **Ultrasonic Sensors**, **Servo Motors**, and **LCD Display** to monitor parking slot availability and manage vehicle entry/exit.

---

## 📌 Overview

In high-density urban zones, parking space management is crucial. This project automates parking slot monitoring and gate control using embedded hardware and real-time feedback via an LCD interface.

---

## 🛠️ Components Used

### Hardware
- Arduino Uno R3
- HC-SR04 Ultrasonic Sensors (for entry, exit, and slot detection)
- SG90 Servo Motor (for gate control)
- 16x2 LCD Display (with I2C module)
- Jumper Wires and Breadboard
- Power Supply (USB or 9V Battery)

### Software
- Arduino IDE
- LiquidCrystal_I2C Library
- Servo Library

---

## ⚙️ How It Works

1. **Vehicle Detection**:
   - Ultrasonic sensor at the **entry gate** detects an approaching car.
   - If slots are available, the **servo motor** opens the gate.

2. **Slot Management**:
   - Ultrasonic sensors above parking slots detect vehicle presence.
   - Slot count is updated in real-time.

3. **Exit Handling**:
   - Exit sensor detects a leaving vehicle.
   - Servo motor opens the **exit gate** and updates slot count.

4. **LCD Display**:
   - Displays live status like:
     - `Car Entering...`
     - `Car Exiting...`
     - `Slots Available: X`
     - `Parking Full`

---

## 🔁 Flowchart

1. Check vehicle at entry ➜
2. Check slot availability ➜
3. Open gate via servo ➜
4. Update slot counter ➜
5. Display message ➜
6. Repeat continuously

---

## 📏 Distance Measurement Formula

Distance (cm) = (Time × 0.034) / 2

This formula is used to calculate the object distance via ultrasonic sensors.

---

## 🧪 Setup Instructions

1. **Circuit Assembly**:
   - Connect ultrasonic sensors to Arduino pins.
   - Attach the servo to a digital PWM pin (e.g., D9).
   - Hook up the LCD (I2C) to SDA/SCL lines.

2. **Upload Code**:
   - Open `smart_parking.ino` in Arduino IDE.
   - Install required libraries (Servo, LiquidCrystal_I2C).
   - Upload to the board.

3. **Power Up**:
   - Use USB or 9V battery to power Arduino.

---

## 📸 Prototype & Demo

Watch the live working prototype:

[🎥 Video Demo](https://drive.google.com/file/d/1N3tjdOKov9u6vTiWK1icO-NgNx5qjf4O/view?usp=sharing)

---

## 🚀 Future Improvements

- Mobile App integration for slot booking
- Camera-based number plate detection
- Cloud-based analytics & monitoring
- Payment gateway support for paid parking
- Solar-powered modules
- Long-range communication (LoRa/GSM)

---

## 🧑‍💻 Authors

- Nitant Jain – AU2340198  
- Pratham Sandesara – AU2340239  
- Param Shah – AU2340192  

Winter Semester 2024–2025  
Course: ENR 206 – Sensors, Instruments, and Experimentation  
Faculty: Prof. Vinod Mall

---

## 📚 References

- [Arduino Official Website](https://www.arduino.cc)
- [ElectronicWings: HC-SR04](https://www.electronicwings.com/sensors-modules/hc-sr04-ultrasonic-sensor)
