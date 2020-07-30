//Wiring for I2C communication:
/*  -SCL from feather to RX on EZO
 *  -SDA from feather to TX on EZO
 */

 #include <Wire.h>

 String getInput();
 bool getConfirmation();
 void changeAddress(String currentAddress, String newAddress);

 void setup(){
  Wire.begin();
  Serial.begin(9600);
  while(!Serial); // Wait for Serial window to opened by user
 }

 void loop(){
  bool hasConfirmation = false;
  String currentAddress;
  String newAddress;

  while(!hasConfirmation){
    Serial.println("Please enter the I2C address the EZO board is currently in: ");
    currentAddress = getInput();
    Serial.println("Please enter a new I2C address: ");
    newAddress = getInput();
    Serial.println("The EZO board at address: " + currentAddress + " will be given the new address: " + newAddress);
    Serial.println("Please confirm this is correct");
    hasConfirmation = getConfirmation();
  }
  delay(1000);
  changeAddress(currentAddress, newAddress);
  Serial.println("The EZO board at address: " + currentAddress + " has been changed to address: " + newAddress);
  delay(5000); // Delay to give user time to change boards if needed
 }

// Function Helpers--------------------------------------------------------
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

void changeAddress(String currentAddress, String newAddress){
  String command;
  command.reserve(String("I2C,").length() + String(newAddress).length());
  command += "I2C,";
  command += newAddress;
  Wire.beginTransmission((int)currentAddress.toInt());
  Wire.write(command.c_str());
  Wire.endTransmission();
}
