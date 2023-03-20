#include "Tries.h"

unordered_map<char, Trie*> Trie::getChildren()
{
    return this->children;
}

void Trie::insert(string word)
{
    Trie* t = this;
    for (char c : word) {
        if (!t->children.count(c)) {
            t->children[c] = new Trie();
            //if(t->head==nullptr)t->head=t;
            //t->trie_list[c]->head=t->head;
        }
        t = t->children[c];
    }
    t->end = true;
}

bool Trie::start_with(string prefix)
{
    Trie* t = this;
    for (char c : prefix) {
        if (!t->children.count(c))return false;
        t = t->children[c];
    }
    return true;
}

bool Trie::search(string word)
{
    Trie* t = this;
    for (char c : word) {
        if (!t->children.count(c))return false;
        t = t->children[c];
    }
    return t->end;
}

Trie::~Trie()
{
    for (unordered_map<char, Trie*>::iterator it = this->children.begin(); it != this->children.end(); ++it) {
        delete it->second;
    }
    delete this;
}
