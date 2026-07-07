#ifndef DETECTOR_H
#define DETECTOR_H

#include <unordered_map>
#include <deque>
#include <string>
#include "trie.h"

class Detector {
    std::unordered_map<std::string, int> ip_count;
    std::deque<time_t> window;
    Trie trie;

public:
    Detector();
    void analyze(std::string ip, std::string payload);
};

#endif