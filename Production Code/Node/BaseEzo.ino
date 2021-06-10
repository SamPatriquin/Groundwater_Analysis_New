#include "BaseEzo.h"
#include "AddressMapping.h"

BaseEzo::BaseEzo(int address){
  this->address = address;
}

String BaseEzo::selectAndRead(){
  muxSelect(this->address); //In MUX select
  
  // Take 5 dud readings to warm the sensor up
  for(int i = 0; i < 5; ++i){
    takeReading();
  }
  return takeReading();
}

String BaseEzo::takeReading(){
  Wire.beginTransmission(address);
  Wire.write("R");
  Wire.endTransmission();

  delay(1000);

  Wire.requestFrom(address, MAX_EZO_RESPONSE_SIZE, true);
  
  unsigned int responseCode = Wire.read();

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
