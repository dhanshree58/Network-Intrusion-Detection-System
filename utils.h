#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <pcap.h>
using namespace std;

string extract_ip(const u_char* packet);
string extract_payload(const u_char* packet, int len);

#endif