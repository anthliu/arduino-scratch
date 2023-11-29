#include <Servo.h>

Servo base_servo;

const int BASE_PIN = 12;
const int BASE_UNIT_DEG = 1;
const int LED_PIN = LED_BUILTIN;
const long LED_BLINK_DUR = 200;

int base_pos = 0;
char code;
boolean received_code = false;

unsigned long previous_millis = 0;

void setup() {
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    base_servo.attach(BASE_PIN);
    Serial.println("<EZARM is ready!>");
}

void loop() {
    if (Serial.available() > 0) {
        code = Serial.read();
        received_code = true;
    }
    if (received_code) {
        received_code = false;
        previous_millis = millis();
        digitalWrite(LED_BUILTIN, HIGH);
        //if (code & 0b10000000) {
        if (code == 'l') {
            // base CC
            base_pos += BASE_UNIT_DEG;
            base_servo.write(base_pos);
            Serial.println("<CC>");
        }
        //if (code & 0b01000000) {
        if (code == 'r') {
            // base CW
            base_pos = BASE_UNIT_DEG;
            base_servo.write(base_pos);
            Serial.println("<CW>");
        }
    } else {
        unsigned long current_millis = millis();
        if (current_millis - previous_millis > LED_BLINK_DUR) {
            digitalWrite(LED_BUILTIN, LOW);
        }
    }
}
