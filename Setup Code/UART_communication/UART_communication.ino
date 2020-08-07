/*
 * Wiring: TX on Feather -> RX on EZO board
 *         RX on Feather -> TX on EZO board
 */
 
#include <SoftwareSerial.h>

#define TO_EZO_RX 1 //TX on Feather
#define TO_EZO_TX 0 //RX on Feather

SoftwareSerial ezo_board(TO_EZO_TX, TO_EZO_RX);

String getInput();

void setup() {
  Serial.begin(9600);
  while(!Serial){} // Wait for Serial window to be opened by user
  pinMode(TO_EZO_RX, OUTPUT);
  pinMode(TO_EZO_TX, INPUT);
  ezo_board.begin(9600);
}

void loop() {
  ezo_board.print(getInput().c_str());
  Serial.print(ezo_board.read());
}

String getInput(){
  bool hasInput = false;
  bool hasConfirmation = false;
  String input;
  while(!hasInput){
    input = Serial.readString();
    if(input.length() > 0){hasInput = true;}
  }
  return input;
}
