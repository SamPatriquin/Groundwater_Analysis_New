#include "Pod.h"

Pod::Pod(String nodeId, int podId):
  tempEzo(podId*10 + 1),
  orpEzo(podId*10 + 2),
  condEzo(podId*10 + 3),
  doEzo(podId*10 +4)
  {
    this->nodeId = nodeId;
  }

void Pod::enable(){
  
}

void Pod::cycle(){
  String temperature = tempEzo.takeReading();
  sendRadioMessage(nodeId, String(tempEzo.getAddress()), temperature);
  tempEzo.toSleep();
  delay(1000);
  
  String orp = orpEzo.takeReading();
  sendRadioMessage(nodeId, String(orpEzo.getAddress()), orp);
  orpEzo.toSleep();
  delay(1000);
  
  condEzo.sendCompensation(temperature);
  delay(1000);
  String conductivity = condEzo.takeReading();
  sendRadioMessage(nodeId, String(condEzo.getAddress()), conductivity);
  condEzo.toSleep();
  delay(1000);
  
  doEzo.sendCompensation(temperature, conductivity);
  delay(1000);
  String dissolvedOxygen = doEzo.takeReading();
  sendRadioMessage(nodeId, String(doEzo.getAddress()), dissolvedOxygen);
  doEzo.toSleep();
}

void Pod::disable(){
  
}
