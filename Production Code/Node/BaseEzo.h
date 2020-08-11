#ifndef _BASEEZO_H
#define _BASEEZO_H

#define MAX_EZO_RESPONSE_SIZE 40

class BaseEzo{
public:
  BaseEzo(int address);
  int getAddress(){return address;}
  void toSleep();
  void enable();
  String takeReading();
  void disable();
protected:
  int address;
};

#endif // _BASEEZO_H
