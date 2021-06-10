#include "Pod.h"

Pod::Pod(String nodeId, int podId):
  tempEzo(podId*10 + 1),
  orpEzo(podId*10 + 2),
  condEzo(podId*10 + 3),
  doEzo(podId*10 +4)
  {
    this->nodeId = nodeId;
  }

void Pod::cycle(){
  String temperature = tempEzo.selectAndRead();
  sendRadioMessage(nodeId, String(tempEzo.getAddress()), temperature);
  delay(100);
  //tempEzo.disable();

  String orp = orpEzo.selectAndRead();
  sendRadioMessage(nodeId, String(orpEzo.getAddress()), orp);
  delay(100);
  //orpEzo.disable();
  
  condEzo.sendCompensation(temperature);
  delay(100);
  String conductivity = condEzo.selectAndRead();
  sendRadioMessage(nodeId, String(condEzo.getAddress()), conductivity);
  delay(100);
  
  doEzo.sendCompensation(temperature, conductivity);
  delay(100);
  String dissolvedOxygen = doEzo.selectAndRead();
  sendRadioMessage(nodeId, String(doEzo.getAddress()), dissolvedOxygen);
  delay(100);
}
