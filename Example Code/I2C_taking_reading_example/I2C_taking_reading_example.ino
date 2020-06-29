// Copyright 2020 Sam Patriquin

// This code serves to be an example of how to send commands to an EZO board and read the response in I2C protocol

// Wiring for I2C communication:
/*   -SCL from feather to RX on EZO
 *   -SDA from feather to TX on EZo
 */

#include <Wire.h> // Necessary for I2C communcation

#define MAX_EZO_RESPONSE_SIZE 40 // This is the maximum byte size that the EZO boards can return 

void setup() {
  Wire.begin(); // Called once, this function intializes the wire library
  Serial.begin(9600);
}

void loop() { 
  
  Wire.beginTransmission(20); // This function starts a transmission with an EZO board at a specified address
  Wire.write("R"); // Use Wire.write("") to send a string command to the EZO board. R requests a reading from the sensor, but this could be any command
  Wire.endTransmission(); // Stop the transmission
  delay(1000); // A delay of at least 1 second is needed for the EZO board to take a reading
  Wire.requestFrom(20, MAX_EZO_RESPONSE_SIZE, true); // Has the EZO board at address 20 send MAX_EZO_RESPONSE_SIZE bytes. Passing true ends the I2C connection after the EZO board sends bytes to Wire.
  
  while(Wire.available()){ // Do this while the EZO board has bytes left to send
   char c = Wire.read(); 
   Serial.print(c);
  }
  Serial.println();
  delay(5000); 
}
