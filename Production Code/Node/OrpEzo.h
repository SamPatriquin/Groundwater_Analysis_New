#ifndef _ORP_EZO_H
#define _ORP_EZO_H
#include "BaseEzo.h"

class OrpEzo: public BaseEzo{
public:
  OrpEzo(int address): BaseEzo(address){ enablePin = A1; pinMode(enablePin, OUTPUT); }
};

#endif // _ORP_EZO_H
