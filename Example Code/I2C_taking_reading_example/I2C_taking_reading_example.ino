// Copyright 2020 Sam Patriquin

// This code serves to be an example of how to take a reading from an EZO board while it is in I2C protocol

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
  Wire.write("R"); // Use Wire.write("") to send a string command to the EZO board. R requests a reading from the sensor.
  Wire.endTransmission(); // Stop the transmission to the specified EZO board
  
  delay(1000); // A delay of at least 1 second is required for the EZO board to take a reading properly. <= IMPORTANT
  
  Wire.requestFrom(20, MAX_EZO_RESPONSE_SIZE, true); // Has the EZO board at address 20 send MAX_EZO_RESPONSE_SIZE bytes and store them in the Wire object. Passing true ends the I2C connection after the EZO board sends bytes to Wire.


  // Wire is an object that stores the response bytes from the EZO. To read a single byte from Wire, use Wire.Read();
  int responseCode = Wire.read(); // The first byte from the EZO response is an integer, 1 is a successful reading

  if(responseCode == 1){ // Important to check if the response was valid
     while(Wire.available()){ // Do this while there are still bytes in Wire to read
        char c = Wire.read(); // The rest of the EZO board response bytes are ASCII so catch each character 
        Serial.print(c);  // Print the response
     }
  }

  Serial.println();
  delay(5000); 
}
