#include <Wire.h>
#include "TemperatureEzo.h"
#include "ConductivityEzo.h"
#include "DissolvedOxygenEzo.h"

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
  condEzo.sendCompensation(String("23.4"));
  delay(1000);
  Serial.println(condEzo.takeReading());
  condEzo.toSleep();
  delay(5000);
}
