#ifndef _RADIO_H
#define _RADIO_H
#include <RH_RF95.h> //Radio Library

//Specific pin number definitions for the feather
#define RFM95_CS 8
#define RFM95_RST 4
#define RFM95_INT 7

//Specify the frequency
#define RF95_FREQ 915.0

#define SIZE_RADIO_BUFFER 50

//Instanciate the singleton instance of rf95 to do radio comms.
RH_RF95 rf95(RFM95_CS, RFM95_INT);

bool setupRadio(){
  pinMode(RFM95_RST, OUTPUT);
  //Set the active low reset pin high
  digitalWrite(RFM95_RST, HIGH);

  //Manual reset
  delay(10);
  digitalWrite(RFM95_RST, LOW);
  delay(10);
  digitalWrite(RFM95_RST, HIGH);
  delay(10);
  
  if (!rf95.init())return false;
  
  if (!rf95.setFrequency(RF95_FREQ))return false;

  rf95.setTxPower(23, false);
  return true;
}

void sendRadioMessage(String node, String address, String reading){
  String message;
  message.reserve(SIZE_RADIO_BUFFER);
  message+= node += String(":") += address += String(":") += reading;
  Serial.println(message.c_str());
  unsigned long startTime = millis();
  rf95.send((uint8_t*)message.c_str(), SIZE_RADIO_BUFFER);
  unsigned long currentTime = millis();
  Serial.println(currentTime - startTime);
}


#endif // _RADIO_H
