#include <Arduino.h>

const int PIN_LED = 13;

void setup() {
    pinMode(PIN_LED, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(PIN_LED, LOW);
    Serial.println("LED off");
    delay(2000);
    digitalWrite(PIN_LED, HIGH);
    Serial.println("LED on");
    delay(2000);
}