#include <SoftwareSerial.h>

/*
 * Wiring: TX on Feather -> RX on EZO board
 *         RX on Feather -> TX on EZO board
 */

#define TO_EZO_RX 1 //TX on Feather
#define TO_EZO_TX 0 //RX on Feather

String getInput();
bool getConfirmation();

SoftwareSerial ezo_board(TO_EZO_TX, TO_EZO_RX);

void setup() {
  Serial.begin(9600);
  while(!Serial){} // Wait for Serial window to be opened by user
  pinMode(TO_EZO_RX, OUTPUT);
  pinMode(TO_EZO_TX, INPUT);
  ezo_board.begin(9600);
}

void loop() {
  bool hasConfirmation = false;
  String address;

  while(!hasConfirmation){
    Serial.println("Please enter an I2C address"); 
    address = getInput();
    String confirmationMessage("Please confirm if the I2C address is correct: ");
    Serial.println("Please confirm the I2C address you input: " + address);
    hasConfirmation = getConfirmation();
  }
  delay(1000);
  ezo_board.println("I2C," + address);
  Serial.println("EZO board has been put into I2C with address: " + address);
  Serial.println("Please prepare next board or exit program");
  delay(10000); // Wait 10 seconds before next EZO board
}


// Function Helpers-------------------------------------------------
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

bool getConfirmation(){
  String input;
  Serial.println("y/n = yes or no");
  while(true){
    input = getInput();
    input.toLowerCase();
    input.trim();
    if(input == String('y')){ return true; }
    else if (input == String('n')){return false;}
    Serial.println("Invalid response, please input y or n");
  }
}
