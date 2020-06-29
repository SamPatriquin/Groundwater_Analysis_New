#include <SoftwareSerial.h>

#define TO_EZO_RX 1
#define TO_EZO_TX 0
#define TO_EZO_GROUND 9

SoftwareSerial ezo_board(TO_EZO_TX, TO_EZO_RX);

void setup() {
  pinMode(TO_EZO_RX, OUTPUT);
  pinMode(TO_EZO_TX, INPUT);

  pinMode(TO_EZO_GROUND, OUTPUT);
  digitalWrite(TO_EZO_GROUND, LOW);

  Serial.begin(9600);

  delay(1000);
  
  ezo_board.begin(9600);

  delay(1000);

  ezo_board.println("I2C, 20 ");
}

// the loop function runs over and over again forever
void loop() {
  
}
