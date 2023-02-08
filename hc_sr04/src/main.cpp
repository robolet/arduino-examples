#include <Arduino.h>

const int trigPin = 11;
const int echoPin = 12;

void setup() {
    // Serial Port begin
    Serial.begin(9600);
    // Define inputs and outputs
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.println("Start ...");
}

void trigger() {
    // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
}

int readAsCM(int duration) {
    // Convert the time into a distance
    return (duration / 2) / 29.1;  // Divide by 29.1 or multiply by 0.0343
}

int readAsInch(int duration) {
    // Convert the time into a distance
    return (duration / 2) / 74;  // Divide by 74 or multiply by 0.0135
}

void loop() {
    trigger();

    // Read the signal from the sensor: a HIGH pulse whose
    // duration is the time (in microseconds) from the sending
    // of the ping to the reception of its echo off of an object.
    pinMode(echoPin, INPUT);
    long duration = pulseIn(echoPin, HIGH);

    Serial.println("Duration read as " + String(duration));
    Serial.print(readAsInch(duration));
    Serial.print("in, ");
    Serial.print(readAsCM(duration));
    Serial.print("cm");
    Serial.println();

    delay(500);
}