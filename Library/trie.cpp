#include "trie.h"


Trie::Trie() {
    isEnd = false;

    next = vector<Trie*>(26, 0);
}

Trie::~Trie() {
    for (auto p : next) delete p;
}

bool Trie::isEmpty() {
    for(Trie * t : this->next) {
        if(t == NULL) {
            return true;
        }
    }
    return false;
}

void Trie::insert(string word) {
    Trie* node = this;
    for (auto c : word) {
        if (node->next[c-'a'] == NULL) {
            node->next[c-'a'] = new Trie();
        }
        node = node->next[c-'a'];
    }
    node->isEnd = true;
}

void Trie::del(string word) {
    stack<Trie*> st;
    Trie* node = this;
    for (auto c : word) {
        node = node->next[c-'a'];
        st.push(node);
        if (node == NULL) return;
    }
    if (!(node->isEnd)) return;
    if (!isLeaf(node)) {
        node->isEnd = false;
        return;
    }
    delete node;
    st.pop();
    while (!st.empty()) {
        node = st.top();
        st.pop();
        if (isLeaf(node) && !(node->isEnd)) delete node;
        else break;
    }
}

bool Trie::search(string word) {
    Trie* node = this;
    for (auto c : word) {
        node = node->next[c-'a'];
        if (node == NULL) return false;
    }
    return node->isEnd;
}

bool Trie::startsWith(string prefix) {
    Trie* node = this;
    for (auto c : prefix) {
        node = node->next[c-'a'];
        if (node == NULL) return false;
    }
    return true;
}

bool Trie::isLeaf(Trie* node) {
    for (auto p : next) {
        if (p) return false;
    }
    return true;
}
