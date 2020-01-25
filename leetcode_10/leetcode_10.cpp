// leetcode_10.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/regular-expression-matching/
/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // v1   200 ms, faster than 17.22% 
        //if (p.empty()) return s.empty();
        //bool first_match = (!s.empty() && (p[0] == s[0] || p[0] == '.'));
        //if (p.length() >= 2 && p[1] == '*') {
        //    return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
        //}
        //else {
        //    return first_match && isMatch(s.substr(1), p.substr(1));
        //}

        // v2  4 ms, faster than 93.34%
        // means isMatch(s[i:], p[j:])
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1));
        dp[s.length()][p.length()] = true;
        for (int i = s.length(); i >= 0; --i) {
            for (int j = p.length() - 1; j >= 0; --j) {
                bool first_match = (i < s.length() && (p[j] == s[i] || p[j] == '.'));
                if (j + 1 < p.length() && p[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || first_match && dp[i + 1][j];
                }
                else {
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
