#include "trie.h"

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(string word) {
    TrieNode* node = root;
    for (char c : word) {
        if (!node->children[c])
            node->children[c] = new TrieNode();
        node = node->children[c];
    }
    node->isEnd = true;
}

bool Trie::search(string text) {
    for (int i = 0; i < text.size(); i++) {
        TrieNode* node = root;
        for (int j = i; j < text.size(); j++) {
            char c = text[j];
            if (!node->children[c]) break;
            node = node->children[c];
            if (node->isEnd) return true;
        }
    }
    return false;
}