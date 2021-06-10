#ifndef _BASEEZO_H
#define _BASEEZO_H

#define MAX_EZO_RESPONSE_SIZE 40

class BaseEzo{
public:
  BaseEzo(int address);
  int getAddress(){return address;}
  String selectAndRead();
  String takeReading();
  void disable();
protected:
  int address;
  int enablePin;
};

#endif // _BASEEZO_H
