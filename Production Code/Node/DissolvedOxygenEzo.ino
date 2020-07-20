#include "DissolvedOxygenEzo.h"

void DissolvedOxygenEzo::sendCompensation(String temperature, String salinity) {
  String tempCommand;
  tempCommand.reserve(String("T,").length() + temperature.length());
  tempCommand += "T,";
  tempCommand += temperature;

  String salinityCommand;
  salinityCommand.reserve(String("S,").length() + salinity.length());
  salinityCommand += "S,";
  salinityCommand += salinity;
  
  Wire.beginTransmission(address);
  Wire.write(tempCommand.c_str());
  
  delay(1000);
  
  Wire.write(salinityCommand.c_str());
  Wire.endTransmission();
}
