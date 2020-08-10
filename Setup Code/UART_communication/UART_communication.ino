/*
 * Wiring: Pin 10 on Feather -> RX on EZO board
 *         Pin 11 on Feather -> TX on EZO board
 */

#include <SoftwareSerial.h>

#define TX_PIN 10 // To rx on EZO
#define RX_PIN 11 // To tx on EZO


SoftwareSerial ezo_board(RX_PIN, TX_PIN);

void setup() {
  Serial.begin(9600);
  while(!Serial){} // Wait for Serial window to be opened by user
  pinMode(TX_PIN, OUTPUT);
  pinMode(RX_PIN, INPUT);
  ezo_board.begin(9600);
 
}

void loop() {
  ezo_board.print(Serial.readString());
  while(ezo_board.available() > 0){
    Serial.print((char)ezo_board.read());
  }
  Serial.println();
}
