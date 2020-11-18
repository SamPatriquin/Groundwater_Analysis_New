#include <Wire.h>
#include "RadioTransmitter.h"
#include "Pod.h"

// Change these for each node
const String NODE_ID("1");
const int NUMBER_OF_PODS = 1;

// Function Declarations
void initializePods(int numberOfPods);

// Needs to be here for scoping issues
Pod pod1(NODE_ID, 1);
Pod pod2(NODE_ID, 2);
Pod pod3(NODE_ID, 3);
Pod pod4(NODE_ID, 4);
Pod pod5(NODE_ID, 5);

void setup() {
  Wire.begin();
  Serial.begin(9600);
  setupRadio();
}

// Node cycle
void loop() {
  switch(NUMBER_OF_PODS){
    case 5:
      pod5.enable();
      pod5.cycle();
      pod5.disable();
      delay(1000);
    case 4:
      pod4.enable();
      pod4.cycle();
      pod4.disable();
      delay(1000);
    case 3:
      pod3.enable();
      pod3.cycle();
      pod3.disable();
      delay(1000);
    case 2:
      pod2.enable();
      pod2.cycle();
      pod2.disable();
      delay(1000);
    case 1:
      pod1.enable();
      pod1.cycle();
      pod1.disable();
      break;
  }
  delay(5000); // Change for how long each node will wait before new cycle
}
