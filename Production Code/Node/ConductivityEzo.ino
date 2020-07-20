#include "ConductivityEzo.h"

void ConductivityEzo::sendCompensation(String temperature){
  String command;
  command.reserve(String("T,").length() + temperature.length());
  command += "T,";
  command += temperature;
  Wire.beginTransmission(address);
  Wire.write(command.c_str());
  Wire.endTransmission();
}
