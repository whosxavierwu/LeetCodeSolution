// leetcode_678.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/valid-parenthesis-string/

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int minLeft = 0;  // min num of open left bracket
        int maxLeft = 0;  // max num of open left bracket
        for (char c : s) {
            minLeft += (c == '(' ? 1 : -1);
            maxLeft += (c == ')' ? -1 : 1);
            if (maxLeft < 0)  // too much right bracket
                return false;
            minLeft = max(minLeft, 0);
        }
        return minLeft == 0;
    }
};

int main()
{
    Solution sol;
    string s = "(())((())()()(*)(*()(())())())()()((()())((()))(*";
    cout << sol.checkValidString(s) << endl;
}
