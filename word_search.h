#pragma once
#ifndef WORD_SEARCH_H
#define WORD_SEARCH_H
#include "Tries.h"
class word_search {
private:
	int m, n;
	Trie* trie;
	vector<string>words;
	vector<vector<char>>board;
	vector<string>words_in_board;
public:
	word_search(vector<vector<char>>board, vector<string>words);
	vector<string>find_words();
	void store_in_trie(string word);
	void backtracking(Trie * parent, int r, int c);
};
#endif // !WORD_SEARCH_H
