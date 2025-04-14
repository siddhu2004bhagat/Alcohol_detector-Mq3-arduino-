#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C LCD at address 0x27

const int mq3Pin = A0;        // MQ-3 analog output
const int ledPin = 6;         // LED pin
const int buzzerPin = 7;      // Buzzer pin

const int alcoholThreshold = 200; // Adjust based on calibration

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("Alcohol Sensor");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
}

void loop() {
  int alcoholLevel = analogRead(mq3Pin); // Read raw sensor value

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Alcohol Value:");
  lcd.setCursor(0, 1);
  lcd.print(alcoholLevel);

  if (alcoholLevel > alcoholThreshold) {
    digitalWrite(ledPin, HIGH);     // Turn on LED

    // Beep effect
    digitalWrite(buzzerPin, HIGH);
    delay(300);
    digitalWrite(buzzerPin, LOW);
    delay(300);

    // Display alert
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ALERT: Alcohol!");
    lcd.setCursor(0, 1);
    lcd.print("Access Denied");
  } else {
    digitalWrite(ledPin, LOW);      // Turn off LED
    digitalWrite(buzzerPin, LOW);   // Turn off buzzer
    delay(1000);                    // Delay before next reading
  }
}
