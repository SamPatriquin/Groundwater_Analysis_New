
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
  String currentAddress(100); // 100 is just to create a String object; has no inherent meaning
  String newAddress;

  while(!hasConfirmation) {
   Serial.println("Enter new address: ");
   String newAdd = getInput();
   if(getConfirmation()) {
    newAddress = String(newAdd);
    hasConfirmation = true; 
   }
  }
  
  // I2C addresses go from 0 to 127 inclusive
  // This loop will go through every possible I2C address and change it to the desire address specified above
  for(int add = 0; add <= 127; add++) {
    currentAddress = String(add);
    Serial.println("Testing address: " + currentAddress);
    delay(1000);
    changeAddress(currentAddress, newAddress);   
  }
  delay(15000); // 15 second delay to give user time to change boards if needed
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
