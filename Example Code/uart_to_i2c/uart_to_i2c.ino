#include <SoftwareSerial.h>

/*
 * Wiring: TX on Feather -> RX on EZO board
 *         RX on Feather -> TX on EZO board
 */

#define TO_EZO_RX 1 //TX on Feather
#define TO_EZO_TX 0 //RX on Feather

SoftwareSerial ezo_board(TO_EZO_TX, TO_EZO_RX);

void setup() {
  pinMode(TO_EZO_RX, OUTPUT);
  pinMode(TO_EZO_TX, INPUT);
  
  ezo_board.begin(9600);

  delay(1000);

  ezo_board.println("I2C, 20 ");
}

// the loop function runs over and over again forever
void loop() {
  
}
