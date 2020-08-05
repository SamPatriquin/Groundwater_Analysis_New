#include <Wire.h>
#include "RadioTransmitter.h"
#include "TemperatureEzo.h"
#include "OrpEzo.h"
#include "ConductivityEzo.h"
#include "DissolvedOxygenEzo.h"

TemperatureEzo tempEzo(11);
OrpEzo orpEzo(12);
ConductivityEzo condEzo(13);
DissolvedOxygenEzo doEzo(14);

// Change these for each node
const String NODE_ID("1");
#define NUMBER_OF_PODS = 1;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  setupRadio();
}

void loop() {
  String temperature = tempEzo.takeReading();
  sendRadioMessage(String(NODE_ID), String(tempEzo.getAddress()), temperature);
  tempEzo.toSleep();
  delay(1000);
  
  String orp = orpEzo.takeReading();
  sendRadioMessage(String(NODE_ID), String(orpEzo.getAddress()), orp);
  orpEzo.toSleep();
  delay(1000);
  
  condEzo.sendCompensation(temperature);
  delay(1000);
  String conductivity = condEzo.takeReading();
  sendRadioMessage(String(NODE_ID), String(condEzo.getAddress()), conductivity);
  condEzo.toSleep();
  delay(1000);
  
  doEzo.sendCompensation(temperature, conductivity);
  delay(1000);
  String dissolvedOxygen = doEzo.takeReading();
  sendRadioMessage(String(NODE_ID), String(doEzo.getAddress()), dissolvedOxygen);
  doEzo.toSleep();
  delay(5000);
}
