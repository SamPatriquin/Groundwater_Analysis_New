#ifndef _POD_H
#define _POD_H

#include "TemperatureEzo.h"
#include "OrpEzo.h"
#include "ConductivityEzo.h"
#include "DissolvedOxygenEzo.h"
#include "RadioTransmitter.h"

class Pod{
public:
  Pod(String node_id, int pod_id);
  void cycle();
private:
  TemperatureEzo tempEzo;
  OrpEzo orpEzo;
  ConductivityEzo condEzo;
  DissolvedOxygenEzo doEzo;
  String node_id;
};

#endif // _POD_H
