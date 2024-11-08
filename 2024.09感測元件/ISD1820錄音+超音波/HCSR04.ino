#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(11, 12);  // Initialize sensor that uses digital pins 13 and 12.

void setup () {
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
    pinMode(10, OUTPUT);
}

void loop () {
    // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
    int x = distanceSensor.measureDistanceCm();
    Serial.println(x);
    if( (x < 15) && (x != -1 )){
       digitalWrite(10, HIGH);
       delay(10);
       digitalWrite(10, LOW);
       delay(10);
       Serial.println("hit....");
    }
    delay(500);
}