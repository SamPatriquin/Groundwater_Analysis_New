#ifndef _POD_H
#define _POD_H

#include "TemperatureEzo.h"
#include "OrpEzo.h"
#include "ConductivityEzo.h"
#include "DissolvedOxygenEzo.h"
#include "RadioTransmitter.h"

class Pod{
public:
  Pod(String nodeId, int podId);
  void cycle();
private:
  TemperatureEzo tempEzo;
  OrpEzo orpEzo;
  ConductivityEzo condEzo;
  DissolvedOxygenEzo doEzo;
  String nodeId;
};

#endif // _POD_H
