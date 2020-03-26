// OperationOnString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "leetcode_140.cpp"

int main()
{
    Solution sol;
    string s = "catsanddog";
    vector<string> wordDict = { "cat","cats","and","sand","dog" };
    vector<string> result = sol.wordBreak(s, wordDict);
    for (string s : result)
        cout << s << endl;
}
