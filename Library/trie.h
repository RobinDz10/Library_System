#ifndef TRIE_H
#define TRIE_H
#include<stdlib.h>
#include<stack>
#include<vector>
#include<string>
using namespace std;
class Trie {
public:
    bool isEnd;

    vector<Trie*> next;

    Trie();

    ~Trie();

    bool isEmpty();

    void insert(string word);
    void del(string word);

    bool search(string word);

    bool startsWith(string prefix);

    bool isLeaf(Trie* node);

};
#endif
