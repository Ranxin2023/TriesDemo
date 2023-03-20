#pragma once
#ifndef TRIES_H
#define TRIES_H
#include<iostream>
#include<unordered_map>
using namespace std;
class Trie {
private:
	bool end = false;
	unordered_map<char, Trie*>children;
public:
	Trie();
	unordered_map<char, Trie*>getChildren();
	void insert(string word);
	bool start_with(string prefix);
	bool search(string word);
	~Trie();
};
#endif // !TRIES_H
