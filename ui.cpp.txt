#include <iostream>
#include <iomanip>
using namespace std;

void show_dashboard(string ip, string status) {
    system("clear");

    cout << "\033[1;36m========================================\n";
    cout << "        REAL-TIME NIDS MONITOR          \n";
    cout << "========================================\033[0m\n\n";

    cout << left << setw(20) << "IP"
         << setw(25) << "STATUS" << endl;

    cout << "----------------------------------------\n";

    cout << setw(20) << ip
         << setw(25) << status << endl;

    cout << "\n========================================\n";
}