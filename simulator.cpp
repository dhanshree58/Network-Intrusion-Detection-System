#include "simulator.h"

void simulate_normal(Detector &d) {
    for(int i=0;i<20;i++)
        d.analyze("192.168.1.10","hello");
}

void simulate_ddos(Detector &d) {
    for(int i=0;i<120;i++)
        d.analyze("10.0.0.5","req");
}

void simulate_sql(Detector &d) {
    d.analyze("172.16.0.2","DROP TABLE users");
}

void simulate_spike(Detector &d) {
    for(int i=0;i<150;i++)
        d.analyze("192.168.1.50","ping");
}