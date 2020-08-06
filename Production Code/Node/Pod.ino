#include "Pod.h"

Pod::Pod(String node_id, int pod_id):
  tempEzo(pod_id*10 + 1),
  orpEzo(pod_id*10 + 2),
  condEzo(pod_id*10 + 3),
  doEzo(pod_id*10 +4)
  {
    this->node_id = node_id;
  }

void Pod::cycle(){
  String temperature = tempEzo.takeReading();
  sendRadioMessage(node_id, String(tempEzo.getAddress()), temperature);
  tempEzo.toSleep();
  delay(1000);
  
  String orp = orpEzo.takeReading();
  sendRadioMessage(node_id, String(orpEzo.getAddress()), orp);
  orpEzo.toSleep();
  delay(1000);
  
  condEzo.sendCompensation(temperature);
  delay(1000);
  String conductivity = condEzo.takeReading();
  sendRadioMessage(node_id, String(condEzo.getAddress()), conductivity);
  condEzo.toSleep();
  delay(1000);
  
  doEzo.sendCompensation(temperature, conductivity);
  delay(1000);
  String dissolvedOxygen = doEzo.takeReading();
  sendRadioMessage(node_id, String(doEzo.getAddress()), dissolvedOxygen);
  doEzo.toSleep();
}
