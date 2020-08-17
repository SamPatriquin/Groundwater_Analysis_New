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
  tempEzo.enable();
  delay(1000);
  tempEzo.disable();

  orpEzo.enable();
  delay(1000);
  orpEzo.disable();
  
  condEzo.enable();
  delay(1000);
  condEzo.diable();
  
  doEzo.enable();
  delay(1000);
  condEzo.diable();
}

void Pod::disable(){
  digitalWrite(enablePin, LOW);
}
