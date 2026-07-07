#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "detector.h"

void simulate_normal(Detector &d);
void simulate_ddos(Detector &d);
void simulate_sql(Detector &d);
void simulate_spike(Detector &d);

#endif