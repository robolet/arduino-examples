#include <Arduino.h>

// Motor A connections
const int enA = 11;
const int in1 = 12;
const int in2 = 13;
// Motor B connections
const int in3 = 7;
const int in4 = 4;
const int enB = 3;

const int minSpeed = 60;
const int maxSpeed = 123;

void setup() {
    // Serial Port begin
    Serial.begin(9600);

    // Set all the motor control pins to outputs
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    // Turn off motors - Initial state
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);

    Serial.println("Engine start ...");
}

void forward() {
    Serial.println("Forward ...");
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void backward() {
    Serial.println("Backward ...");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

void stop() {
    Serial.println("Stop ...");
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

void speed(int sp) {
    Serial.print("Set speed to: ");
    Serial.println(sp);
    analogWrite(enA, sp);
    analogWrite(enB, sp);
}

// This function lets you control spinning direction of motors
void directionControl() {

    speed(maxSpeed);

    forward();
    delay(2000);

    backward();
    delay(2000);

    stop();
    delay(2000);
}

// This function lets you control speed of the motors
void speedControl() {

    forward();

    // Accelerate from zero to maximum speed
    Serial.println("Speed up ...");
    for (int i = minSpeed; i < maxSpeed; i++) {
        speed(i);
        delay(100);
    }

    // Decelerate from maximum speed to zero
    Serial.println("Slow down ...");
    for (int i = maxSpeed; i >= minSpeed; --i) {
        speed(i);
        delay(100);
    }

    stop();
}

void loop() {
    Serial.println("directionControl ...");
    directionControl();
    delay(2000);
    Serial.println("speedControl ...");
    speedControl();
    delay(2000);
}