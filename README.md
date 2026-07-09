# Enhanced Car Safety System 

An IoT-based accident detection and emergency notification system that automatically alerts hospitals, police, and family members when a vehicular collision occurs — without relying on airbag deployment.

##  Overview

Road traffic accidents are a leading cause of injury and death worldwide, and delays in emergency notification often cost lives. This project uses a vibration sensor and GSM module to detect a collision in real time and immediately send SMS alerts and a call to predefined emergency contacts, reducing response time and improving survival outcomes.

##  Objectives

- Develop a reliable collision detection mechanism using sensors.
- Implement real-time SMS/call alerts to emergency services and family.
- Ensure seamless integration with vehicle electronics.
- Validate the system through simulated and real-world testing.

##  How It Works

1. System powers on and initializes the microcontroller and GSM module.
2. Vibration sensor continuously monitors for sudden impacts.
3. Sensor data is compared against a threshold to detect a genuine collision (with debouncing/filtering to avoid false positives from bumps or potholes).
4. On confirmed collision, the system prepares and sends an SMS with alert details to emergency contacts and places a call via the GSM module.
5. System resets (manually or automatically) to resume monitoring.

##  Hardware Requirements

- Arduino Nano
- SIMCOM A7670C GSM Module + active SIM card
- REES52 Vibration Sensor
- LM2596 Buck Converter
- Li-ion Battery
- Jumper wires / prototyping board

##  Software Requirements

- Arduino IDE
- C++ (Arduino firmware)

##  Results

- Accurately detects collisions using vibration sensor data.
- Minimizes false positives via filtering/debouncing.
- Sends SMS alerts promptly upon detecting a collision.
- Reliable operation across varied conditions with basic fault tolerance.


##  Applications

- Automatic emergency service notification
- Family alert system
- Hospital pre-arrival notification
- Fleet and public transport safety
- Smart city traffic safety integration

##  Advantages

- Fast, automated emergency response
- Works without airbag deployment
- Easily integrated into existing/new vehicles
- Scalable (e.g., add GPS for location tracking)

##  Limitations

- Detection accuracy depends on sensor calibration
- Environmental factors (rain, snow, fog) may affect reliability
- May trigger false alerts on hard braking or rough roads

##  Future Scope

- Add gyroscope/camera sensors for richer accident analysis
- Cloud connectivity for real-time monitoring, predictive analytics, and fleet management
- GPS integration for precise location tracking
- Integration with smart city traffic infrastructure

##  Paper Publication

Paper was published in the Grenze Scientific Society entitled as"Design and Development of Enhanced Car SafetySystem " in the year 2024.(https://drive.google.com/file/d/14fFmXGquv8QropdXoqemUUmMEst6w_h7/view?usp=sharing)
