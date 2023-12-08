#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial HC12(10, 11);

__attribute__((unused))
void setup() {
    Serial.begin(9600);
    HC12.begin(9600);
}

__attribute__((unused))
void loop() {
    while (HC12.available()) {
        Serial.write(HC12.read());
    }

    while (Serial.available()) {
        HC12.write(Serial.read());
    }
}