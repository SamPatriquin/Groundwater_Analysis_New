#ifndef _DISSOLVED_OXYGEN_EZO_H
#define _DISSOLVED_OXYGEN_EZO_H

#include "BaseEzo.h"

class DissolvedOxygenEzo: public BaseEzo {
  public:
    DissolvedOxygenEzo(int address): BaseEzo(address) {}
    void sendCompensation(String temperature, String salinity);
};

#endif //_DISSOLVED_OXYGEN_EZO_H
