#include <Wire.h>
#include "TemperatureEzo.h"
#include "ConductivityEzo.h"

TemperatureEzo tempEzo(20);
ConductivityEzo condEzo(21);

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  String temperature = tempEzo.takeReading();
  Serial.println(temperature);
  tempEzo.toSleep();
  delay(1000);
  condEzo.sendCompensation(temperature);
  delay(1000);
  Serial.println(condEzo.takeReading());
  condEzo.toSleep();
  delay(5000);
}