#include <Servo.h>

Servo base_servo;

int BASE_PIN = 12;
int pos = 0;    // variable to store the servo position

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    base_servo.attach(BASE_PIN);
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
                                          // in steps of 1 degree
        base_servo.write(pos);            // tell servo to go to position in variable 'pos'
        delay(15);                        // waits 15ms for the servo to reach the position
    }
    digitalWrite(LED_BUILTIN, LOW);
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        base_servo.write(pos);            // tell servo to go to position in variable 'pos'
        delay(15);                        // waits 15ms for the servo to reach the position
    }
}
