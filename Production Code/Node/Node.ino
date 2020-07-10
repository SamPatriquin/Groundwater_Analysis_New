#include <Wire.h>
#include "BaseEzo.h"

BaseEzo myEzo(20);

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  Serial.println(myEzo.takeReading());
  myEzo.toSleep();
  delay(5000);
}
