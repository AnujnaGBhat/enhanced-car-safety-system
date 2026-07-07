/*
  Enhanced Car Safety System
  Accident Detection and Emergency Alert using Arduino Nano + SIMCOM A7670C GSM Module

  Description:
  Monitors a vibration sensor for collision-level impact. On detection, sends an
  SMS alert and places a call to a predefined emergency contact number using the
  SIMCOM A7670C GSM module over UART with AT commands.

  Hardware:
    - Arduino Nano (ATmega328P)
    - SIMCOM A7670C GSM Module
    - REES52 Vibration Sensor
    - LM2596 Buck Converter
    - Li-ion Battery power supply

  NOTE: Replace "XXXXXXXXXX" below with your actual emergency contact number
  before uploading.
*/

#include <SoftwareSerial.h>

SoftwareSerial SIM7670Serial(2, 3); // RX, TX
int sencepin = 12;
int sencev;

void sendATCommand(const char* cmd, const char* expectedResponse, unsigned long timeout) {
  SIM7670Serial.println(cmd);
  String response = "";
  unsigned long startTime = millis();
  bool responseOK = false;

  while (millis() - startTime < timeout) {
    while (SIM7670Serial.available() > 0) {
      char c = SIM7670Serial.read();
      response += c;
    }
    if (response.indexOf(expectedResponse) != -1) {
      responseOK = true;
      break; // found it
    }
  }
  Serial.println(response);

  if (responseOK)
    Serial.println("Response OK");
  else
    Serial.println("Timeout without expected Response");
}

void setup() {
  Serial.begin(115200);
  SIM7670Serial.begin(115200);
  pinMode(sencepin, INPUT);

  sendATCommand("AT+CGMM", "OK", 1000);   // check communication
  sendATCommand("AT+CMGF=1", "OK", 1000); // set SMS format to text
}

void sendSMS(String number, String message) {
  String cmd = "AT+CMGS=\"" + number + "\"\r\n";
  SIM7670Serial.print(cmd);
  delay(100);
  SIM7670Serial.println(message);
  delay(100);
  SIM7670Serial.write(0x1A); // send ctrl-z to terminate SMS
  delay(100);
}

void loop() {
  sencev = digitalRead(sencepin);

  if (sencev == 0) {
    sendSMS("XXXXXXXXXX", "Emergency");
    SIM7670Serial.println("ATD +91XXXXXXXXXX;");
    delay(3000);
  }

  if (SIM7670Serial.available()) {
    String response = SIM7670Serial.readString();
    Serial.println(response);

    // Check if the response indicates a call has been connected
    if (response.indexOf("CONNECT") != -1) {
      Serial.println("Call Connected");
      // Add code here to perform actions during the call
    }
  }
}
