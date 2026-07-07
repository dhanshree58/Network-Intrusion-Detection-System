#include <pcap.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <iostream>
#include "live_capture.h"

using namespace std;

Detector *global_detector;

void packet_handler(u_char *, const struct pcap_pkthdr *, const u_char *packet) {

    struct ip *ip_header = (struct ip*)(packet + 14);
    string src_ip = inet_ntoa(ip_header->ip_src);

    global_detector->analyze(src_ip, "network");
}

void start_live_capture(Detector &d) {
    char errbuf[PCAP_ERRBUF_SIZE];
    global_detector = &d;

    pcap_t *handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

    if (!handle) {
        cerr << "Error: " << errbuf << endl;
        return;
    }

    cout << "Capturing real traffic...\n";
    pcap_loop(handle, 50, packet_handler, NULL);

    pcap_close(handle);
}