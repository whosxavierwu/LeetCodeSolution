// leetcode_79.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/word-search/
/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    bool dfsSearch(vector<vector<char>>& board, string& word, int k, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size())
            return false;
        if (board[i][j] != word[k])
            return false;
        if (k == word.size() - 1)
            return true;

        char cur = board[i][j];
        board[i][j] = '*';
        bool search_neighbour = dfsSearch(board, word, k + 1, i - 1, j)
            || dfsSearch(board, word, k + 1, i + 1, j)
            || dfsSearch(board, word, k + 1, i, j - 1)
            || dfsSearch(board, word, k + 1, i, j + 1);
        board[i][j] = cur;
        return search_neighbour;
    }
    bool exist(vector<vector<char>>& board, string word) {
        // 20 ms, faster than 96.23% 
        if (word.empty())
            return true;
        if (board.empty() || board[0].empty())
            return false;
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (dfsSearch(board, word, 0, i, j))
                    return true;
        return false;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
