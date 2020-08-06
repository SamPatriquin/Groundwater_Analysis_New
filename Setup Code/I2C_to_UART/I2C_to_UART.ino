#include <Wire.h>

/*
 * Wiring: TX on Feather -> RX on EZO board
 *         RX on Feather -> TX on EZO board
 */
 
String getInput();
bool getConfirmation();

void setup() {
  Serial.begin(9600);
  Wire.begin();
  while(!Serial){} // Wait for Serial window to be opened by user
}

void loop() {
  bool hasConfirmation = false;
  String address;

  while(!hasConfirmation){
    Serial.println("Please enter the I2C address of the board that you want to put in UART"); 
    address = getInput();
    Serial.println("Please confirm the I2C address you input: " + address);
    hasConfirmation = getConfirmation();
  }
  delay(1000);
  Wire.beginTransmission((int)address.toInt()); // toInt() creates a long int, we need to cast to int
  Wire.write("Baud,9600");
  Wire.endTransmission();
  delay(10000); // 10 second delay for next board
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
