//Wiring for I2C communication:
/*  -SCL from feather to RX on EZO
 *  -SDA from feather to TX on EZO
 */

 #include <Wire.h>

 #define CURRENT_ADDRESS 21 // current i2c address that the EZO board is in, needed for communication
 #define NEW_ADDRESS 3  // i2c address wanted for the EZO board

 void setup(){
  Wire.begin();
  Serial.begin(9600);

  String command;
  command.reserve(String("I2C,").length() + String(NEW_ADDRESS).length());
  command += "I2C,";
  command += NEW_ADDRESS;
  Wire.beginTransmission(CURRENT_ADDRESS);
  Wire.write(command.c_str());
  Wire.endTransmission();
 }

 void loop(){
  
 }
