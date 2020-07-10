#include <Wire.h>
#include "TemperatureEzo.h"

TemperatureEzo myEzo(20);

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  Serial.println(myEzo.takeReading());
  myEzo.toSleep();
  delay(5000);
}
