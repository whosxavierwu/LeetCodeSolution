// FindPathInMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "leetcode_212.cpp"

int main()
{
    Solution sol;
    vector<vector<char>> board = {};
    board.push_back({ 'o','a','a','n' });
    board.push_back({ 'e','t','a','e' });
    board.push_back({ 'i','h','k','r' });
    board.push_back({ 'i','f','l','v' });
    vector<string> words = { "oath","pea","eat","rain" };
    vector<string> result = sol.findWords(board, words);
    for (string s : result)
        cout << s << endl;
}
