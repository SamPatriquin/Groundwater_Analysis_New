#include "RadioReceiver.h"

void setup() {
  Serial.begin(9600);
  setupRadio();
}

void loop() {
  if (rf95.available()) {
    uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);
    if (rf95.recv(buf, &len)){
      Serial.println((char*)buf);
    }
  }
}
