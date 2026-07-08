#include "utils.h"
#include <netinet/ip.h>
#include <arpa/inet.h>

string extract_ip(const u_char* packet) {
    struct ip* iphdr = (struct ip*)(packet + 14);
    return inet_ntoa(iphdr->ip_src);
}

string extract_payload(const u_char* packet, int len) {
    const char* data = (char*)(packet + 54);
    return string(data, len - 54);
}