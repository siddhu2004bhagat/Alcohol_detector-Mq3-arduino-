# Alcohol_detector-Mq3-arduino-
🍷 Alcohol Detector using MQ3 Sensor and Arduino
Created by Sk_ElectroTech
Developed by Siddhu
📧 Contact: siddhu200410@gmail.com

📌 Project Description
This project is a simple alcohol detection system using an MQ3 gas sensor, Arduino, and an I2C LCD display. It can detect the presence of alcohol vapor in the air and display the result in real time on the LCD screen.

Useful for:

Breath analyzers

Safety systems in vehicles

Alcohol level alerts in workspaces

🧠 How It Works
The MQ3 sensor measures the concentration of alcohol in the air.

The analog value from the sensor is read using Arduino.

If the value exceeds a defined threshold (sensorThres = 500), the system displays "ALCOHOL DETECT".

If the value is below the threshold, it shows "NORMAL LEVEL...".

All readings are also printed to the Serial Monitor.

🔧 Hardware Required
Component	Quantity
Arduino UNO/Nano	1
MQ3 Alcohol Sensor	1
I2C LCD (16x2)	1
Jumper Wires	As needed
Breadboard (optional)	1
🖥️ Circuit Connections
MQ3 Sensor Pin	Connects To
VCC	5V on Arduino
GND	GND on Arduino
AOUT	A3 (Analog Pin)
I2C LCD Pin	Connects To
VCC	5V on Arduino
GND	GND on Arduino
SDA	A4 (for UNO/Nano)
SCL	A5 (for UNO/Nano)
🧾 Arduino Code Overview
cpp
Copy
Edit
int smokeA0 = A3;              // MQ3 analog output
int sensorThres = 500;         // Alcohol detection threshold
...
if (analogSensor > sensorThres) {
  lcd.print("ALCOHOL DETECT");
} else {
  lcd.print("NORMAL LEVEL...");
}
📦 Libraries Used
LiquidCrystal_I2C

Install it via Arduino Library Manager or manually from the GitHub repo.

✅ Setup Instructions
Wire up the components as per the circuit.

Upload the code to your Arduino.

Open Serial Monitor at 9600 baud to see live readings.

Breathe near the MQ3 sensor or expose it to alcohol vapor to test detection.

📊 Output
LCD Display shows the current alcohol status:

"ALCOHOL DETECT" when levels are high.

"NORMAL LEVEL..." when levels are within safe range.

Serial Monitor prints raw sensor values for analysis.

🚀 Future Improvements
Add a buzzer for audible alerts.

Display percentage or ppm values.

Log data to an SD card or send to a mobile app via Bluetooth/WiFi.

Calibrate sensor more precisely for specific use cases.

📢 Disclaimer
This project is not a certified alcohol tester and should not be used for legal or medical purposes. It's purely for educational and experimental use.

