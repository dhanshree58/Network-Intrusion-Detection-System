#include "detector.h"
#include "ui.h"
#include "prevention.h"
#include <iostream>
#include <ctime>

using namespace std;

Detector::Detector() {
    trie.insert("DROP");
    trie.insert("SELECT");
    trie.insert("admin");
}

void handle_attack(string ip, string type) {
    int choice;
    cout << "\n ALERT: " << type << " from " << ip << endl;
    cout << "1.Block IP  2.Ignore  3.Monitor\nChoice: ";
    cin >> choice;

    if (choice == 1) block_ip(ip);
}

void Detector::analyze(string ip, string payload) {

    ip_count[ip]++;

    if (ip_count[ip] > 50) {
        show_dashboard(ip, "DDoS Attack 🚨");
        handle_attack(ip, "DDoS Attack");
    }

    if (trie.search(payload)) {
        show_dashboard(ip, "SQL Injection 🚨");
        handle_attack(ip, "SQL Injection");
    }

    time_t now = time(0);
    window.push_back(now);

    while (!window.empty() && now - window.front() > 5)
        window.pop_front();

    if (window.size() > 100) {
        show_dashboard(ip, "Traffic Spike 🚨");
        handle_attack(ip, "Traffic Spike");
    }
}