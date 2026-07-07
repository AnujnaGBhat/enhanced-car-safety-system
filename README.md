# Enhanced Car Safety System 🚗🚨

An IoT-based accident detection and emergency notification system that automatically alerts hospitals, police, and family members when a vehicular collision occurs — without relying on airbag deployment.

## 📖 Overview

Road traffic accidents are a leading cause of injury and death worldwide, and delays in emergency notification often cost lives. This project uses a vibration sensor and GSM module to detect a collision in real time and immediately send SMS alerts and a call to predefined emergency contacts, reducing response time and improving survival outcomes.

## 🎯 Objectives

- Develop a reliable collision detection mechanism using sensors.
- Implement real-time SMS/call alerts to emergency services and family.
- Ensure seamless integration with vehicle electronics.
- Validate the system through simulated and real-world testing.

## ⚙️ How It Works

1. System powers on and initializes the microcontroller and GSM module.
2. Vibration sensor continuously monitors for sudden impacts.
3. Sensor data is compared against a threshold to detect a genuine collision (with debouncing/filtering to avoid false positives from bumps or potholes).
4. On confirmed collision, the system prepares and sends an SMS with alert details to emergency contacts and places a call via the GSM module.
5. System resets (manually or automatically) to resume monitoring.

## 🧩 System Architecture

| Component | Model | Purpose |
|---|---|---|
| Microcontroller | Arduino Nano (ATmega328P) | Processes sensor data, controls modules |
| GSM Module | SIMCOM A7670C | Sends SMS/call alerts over cellular network |
| Voltage Regulator | LM2596 | Steps down power for stable supply |
| Vibration Sensor | REES52 | Detects collision impact |
| Power Source | Li-ion Battery | Powers the system |

See `/hardware/datasheets` for full component specs and `/docs/block_diagram.png` for the system architecture.

## 🛠️ Hardware Requirements

- Arduino Nano
- SIMCOM A7670C GSM Module + active SIM card
- REES52 Vibration Sensor
- LM2596 Buck Converter
- Li-ion Battery
- Jumper wires / prototyping board

## 💻 Software Requirements

- Arduino IDE
- C++ (Arduino firmware)

## 🚀 Getting Started

1. Clone this repository:
   ```bash
   git clone https://github.com/<your-username>/enhanced-car-safety-system.git
   ```
2. Open `src/accident_detection_alert.ino` in the Arduino IDE.
3. Update the emergency contact number in the code:
   ```cpp
   sendSMS("XXXXXXXXXX", "Emergency");
   SIM7670Serial.println("ATD +91XXXXXXXXXX;");
   ```
4. Connect the hardware as per the circuit diagram in `/hardware/circuit_diagram`.
5. Upload the code to the Arduino Nano.
6. Power on the system — wait for the GSM module's blue LED to indicate network connection.

## 📊 Results

- Accurately detects collisions using vibration sensor data.
- Minimizes false positives via filtering/debouncing.
- Sends SMS alerts promptly upon detecting a collision.
- Reliable operation across varied conditions with basic fault tolerance.

See `/images/output_screenshots` for sample outputs.

## 🌍 Applications

- Automatic emergency service notification
- Family alert system
- Hospital pre-arrival notification
- Fleet and public transport safety
- Accident data collection for legal/insurance use
- Smart city traffic safety integration

## ✅ Advantages

- Fast, automated emergency response
- Works without airbag deployment
- Easily integrated into existing/new vehicles
- Scalable (e.g., add GPS for location tracking)

## ⚠️ Limitations

- Detection accuracy depends on sensor calibration
- Environmental factors (rain, snow, fog) may affect reliability
- May trigger false alerts on hard braking or rough roads

## 🔮 Future Scope

- Add gyroscope/camera sensors for richer accident analysis
- Cloud connectivity for real-time monitoring, predictive analytics, and fleet management
- GPS integration for precise location tracking
- Integration with smart city traffic infrastructure

## 📚 References

Key references and prior work are listed in [`docs/literature_survey.md`](docs/literature_survey.md). Full citations available in the project report.

## 📄 License

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

## 🙋 Author

Add your name, institution, and contact/LinkedIn/GitHub links here.
