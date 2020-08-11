#include "Pod.h"

Pod::Pod(String nodeId, int podId):
  tempEzo(podId*10 + 1),
  orpEzo(podId*10 + 2),
  condEzo(podId*10 + 3),
  doEzo(podId*10 +4)
  {
    this->nodeId = nodeId;
    switch(podId){
      case 1:
        enablePin = 9;
        break;
      case 2:
        enablePin = 10;
        break;
      case 3:
        enablePin = 11;
        break;
      case 4:
        enablePin = 12;
        break;
      case 5:
        enablePin = 13;
        break;   
    }
    pinMode(enablePin, OUTPUT);
  }

void Pod::enable(){
  digitalWrite(enablePin, HIGH);
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
  digitalWrite(enablePin, LOW);
}
