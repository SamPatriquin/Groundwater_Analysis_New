#include <Wire.h>
#include "Radio.h"
#include "TemperatureEzo.h"
#include "OrpEzo.h"
#include "ConductivityEzo.h"
#include "DissolvedOxygenEzo.h"

TemperatureEzo tempEzo(11);
OrpEzo orpEzo(12);
ConductivityEzo condEzo(13);
DissolvedOxygenEzo doEzo(14);

// Change these for each node
#define NODE_ID = 1;
#define NUMBER_OF_PODS = 1;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  setupRadio();
}

void loop() {
  String temperature = tempEzo.takeReading();
  Serial.println(temperature);
  tempEzo.toSleep();
  delay(1000);
  String orp = orpEzo.takeReading();
  Serial.println(orp);
  orpEzo.toSleep();
  delay(1000);
  condEzo.sendCompensation(temperature);
  delay(1000);
  String conductivity = condEzo.takeReading();
  Serial.println(conductivity);
  condEzo.toSleep();
  delay(1000);
  doEzo.sendCompensation(temperature, conductivity); // Compensation not working for DO, look into this. Also see if you can fix the string reserves, I think they're not needed.
  delay(1000);
  String dissolvedOxygen = doEzo.takeReading();
  Serial.println(dissolvedOxygen);
  doEzo.toSleep();
  delay(5000);
}
