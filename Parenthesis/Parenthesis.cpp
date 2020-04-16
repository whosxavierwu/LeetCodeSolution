// Parenthesis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "leetcode_678.cpp"
using namespace std;

int main()
{
    string s = "(())((())()()(*)(*()(())())())()()((()())((()))(*";
    Solution sol;
    cout << sol.checkValidString(s) << endl;
}
