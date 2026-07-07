#ifndef TRIE_H
#define TRIE_H
#include <map>
#include <string>
using namespace std;

class TrieNode {
public:
    map<char, TrieNode*> children;
    bool isEnd;
    TrieNode() { isEnd = false; }
};

class Trie {
    TrieNode* root;
public:
    Trie();
    void insert(string word);
    bool search(string text);
};

#endif