#include "word_search.h"

word_search::word_search(vector<vector<char>> board, vector<string> words)
{
    this->trie = new Trie();
    this->m = board.size();
    this->n = board[0].size();
    this->board = board;
    this->words = words;
}

vector<string> word_search::find_words()
{
    
    //this->word_set=set<string>(words.begin(), words.end());
    for (string word : words) {
        store_in_trie(word);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (trie->getChildren().count(board[i][j])) {
                backtracking(trie, i, j);
            }
        }
    }
    return this->words_in_board;
}

void word_search::store_in_trie(string word)
{
    Trie* t = this->trie;
    for (char c : word) {
        if (!t->getChildren().count(c)) {
            t->getChildren()[c] = new Trie();
        }
        t = t->getChildren()[c];
    }
    t->word = word;
}

void word_search::backtracking(Trie* parent, int r, int c)
{
}
