#ifndef _CONDUCTIVITY_EZO_H
#define _CONDUCTIVITY_EZO_H

class ConductivityEzo: public BaseEzo{
public:
  ConductivityEzo(int address): BaseEzo(address){}
  void sendCompensation(String temperature);
};


#endif // _CONDUCTIVITY_EZO_H
