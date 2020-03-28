// https://leetcode.com/problems/word-search-ii/
/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.

Input:
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//class Solution {
//public:
//    // 1296 ms, faster than 5.02%
//    bool dfsSearch(vector<vector<char>>& board, 
//        const string& word, int k, int i, int j, vector<string>& results) {
//        if (i < 0 || j < 0 
//            || i >= board.size() || j >= board[0].size() 
//            || board[i][j] != word[k])
//            return false;
//        if (k == word.size() - 1) {
//            results.push_back(word);
//            return true;
//        }
//        board[i][j] = '*';
//        bool found = false;
//        if (dfsSearch(board, word, k + 1, i - 1, j, results)
//            || dfsSearch(board, word, k + 1, i + 1, j, results)
//            || dfsSearch(board, word, k + 1, i, j - 1, results)
//            || dfsSearch(board, word, k + 1, i, j + 1, results)) {
//            found = true;
//        }
//        board[i][j] = word[k];
//        return found;
//    }
//    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//        int N = board.size();
//        int M = board[0].size();
//        if (N == 0 || M == 0)
//            return {};
//        vector<string> results;
//        for (string& word : words) {
//            bool wordFound = false;
//            for (int i = 0; i < N; ++i) {
//                for (int j = 0; j < M; ++j)
//                    if (board[i][j] == word[0] 
//                        && dfsSearch(board, word, 0, i, j, results)) {
//                        wordFound = true;
//                        break;
//                    }
//                if (wordFound)
//                    break;
//            }
//        }
//            
//        return results;
//    }
//};

class TrieNode {
public:
    TrieNode* children[26] = {};
    bool isEnd = false;

    TrieNode() {}

    void insert(const string& word) {
        TrieNode* node = this;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr)
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }
};

class Solution {
    // 188 ms, faster than 34.97% 
    void dfsSearch(vector<vector<char>>& board, TrieNode* trie, 
        int i, int j, string word, unordered_set<string>& results) {
        if (i < 0 || j < 0 
            || i >= board.size() || j >= board[0].size()
            || board[i][j] == '*'
            || trie->children[board[i][j] - 'a'] == NULL)
            return;
        trie = trie->children[board[i][j] - 'a'];
        word += board[i][j];
        if (trie->isEnd)
            results.insert(word);
        char c = board[i][j];
        board[i][j] = '*';
        dfsSearch(board, trie, i - 1, j, word, results);
        dfsSearch(board, trie, i + 1, j, word, results);
        dfsSearch(board, trie, i, j - 1, word, results);
        dfsSearch(board, trie, i, j + 1, word, results);
        board[i][j] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int N = board.size();
        int M = board[0].size();
        if (N == 0 || M == 0)
            return {};

        TrieNode* trie = new TrieNode();
        for (string& word: words)
            trie->insert(word);

        unordered_set<string> results;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                dfsSearch(board, trie, i, j, "", results);
        return vector<string>(results.begin(), results.end());
    }
};

