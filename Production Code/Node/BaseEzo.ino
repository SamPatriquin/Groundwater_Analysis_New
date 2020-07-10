#include "BaseEzo.h"

BaseEzo::BaseEzo(int address){
  this->address = address;
}

void BaseEzo::toSleep(){
  Wire.beginTransmission(address);
  Wire.write("Sleep");
  Wire.endTransmission();
}

String BaseEzo::takeReading(){
  Wire.beginTransmission(address);
  Wire.write("R");
  Wire.endTransmission();

  delay(1000);

  Wire.requestFrom(20, MAX_EZO_RESPONSE_SIZE, true);
  
  int responseCode = Wire.read();
  
  if( responseCode == 1 ) { // 1 means the response is valid
    char current;
    String response;
    response.reserve(MAX_EZO_RESPONSE_SIZE);
    while(Wire.available()){
      current = Wire.read();
      response += current;
    }
    return response;
  } else { // Anything other than one is an error
    return String("ERR");
  }
}
