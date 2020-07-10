#include "ConductivityEzo.h"

void ConductivityEzo::sendCompensation(String temperature){
  String command;
  command.reserve(20); // More than enoughh
  command += "T,";
  command += temperature;
  Wire.beginTransmission(address);
  Wire.write(command.c_str());
  Wire.endTransmission();
}
