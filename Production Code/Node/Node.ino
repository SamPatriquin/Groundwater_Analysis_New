#include <Wire.h>
#include "RadioTransmitter.h"
#include "Pod.h"

// Change these for each node
const String NODE_ID("1");
const int NUMBER_OF_PODS = 2;

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
      pod5.cycle();
      delay(1000);
    case 4:
      pod4.cycle();
      delay(1000);
    case 3:
      pod3.cycle();
      delay(1000);
    case 2:
      pod2.cycle();
      delay(1000);
    case 1:
      pod1.cycle();
      break;
  }
  delay(5000); // Change for how long each node will wait before new cycle
}
