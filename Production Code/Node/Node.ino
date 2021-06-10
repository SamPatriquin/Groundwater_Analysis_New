#include <Wire.h>
#include <Adafruit_SleepyDog.h>
#include "AddressMapping.h"
#include "RadioTransmitter.h"
#include "Pod.h"

// Change these for each node
const String NODE_ID("1"); //CHANGE THIS FOR EACH NODE UPLOADING TOO
const int NUMBER_OF_PODS = 4; //DO NOT CHANGE

// Function Declarations
void initializePods(int numberOfPods);

// Needs to be here for scoping issues
Pod pod1(NODE_ID, 1);
Pod pod2(NODE_ID, 2);
Pod pod3(NODE_ID, 3);
Pod pod4(NODE_ID, 4);

void setup() {
  setMuxPinModes(); //Comes from AddressMapping.h
  Wire.begin();
  Serial.begin(9600);
  setupRadio(); //Comes from RadioTransmitter.h
}

// Node cycle
void loop() {
  enableMux(); //Comes from AddressMapping.h
  switch(NUMBER_OF_PODS){
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
      delay(1000);
      break;
  }
  disableMux(); //Comes from AddressMapping.h
  long milis_left = 2000; //CHANGE THIS FOR NODE CYCLE TIMING (900000) is 15 min
  while(milis_left>0)milis_left-=Watchdog.sleep();
}
