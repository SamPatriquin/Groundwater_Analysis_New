#ifndef _TEMPERATURE_EZO_H
#define _TEMPERATURE_EZO_H
#include "BaseEzo.h"

class TemperatureEzo: public BaseEzo{
public:
  TemperatureEzo(int address): BaseEzo(address){}
};

#endif // _TEMPERATURE_EZO_H
