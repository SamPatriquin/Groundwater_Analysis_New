#ifndef _RADIO_RECIEVER_H
#define _RADIO_RECIEVER_H
#include <RH_RF95.h>
 
#define RFM95_CS 8
#define RFM95_RST 4
#define RFM95_INT 7
 
#define RF95_FREQ 915.0

RH_RF95 rf95(RFM95_CS, RFM95_INT);
 
bool setupRadio(){
  pinMode(RFM95_RST, OUTPUT);
  digitalWrite(RFM95_RST, HIGH);

  //Manual reset
  digitalWrite(RFM95_RST, LOW);
  delay(10);
  digitalWrite(RFM95_RST, HIGH);
  delay(10);
 
  if (!rf95.init()) { return false; }
 
  if (!rf95.setFrequency(RF95_FREQ)) { return false; }
  rf95.setTxPower(23, false);
  return true;
}
 
uint8_t* recieveRadioMessage(){
  if (rf95.available()) {
    uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);
    if (rf95.recv(buf, &len)){
      return buf;
    }
  }
}

#endif //_RADIO_RECIEVER_H
