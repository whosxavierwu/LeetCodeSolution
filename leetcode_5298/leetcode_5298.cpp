// leetcode_5298.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-169/problems/verbal-arithmetic-puzzle/
/*
Given an equation, represented by words on left side and the result on right side.

You need to check if the equation is solvable under the following rules:

Each character is decoded as one digit (0 - 9).
Every pair of different characters they must map to different digits.
Each words[i] and result are decoded as one number without leading zeros.
Sum of numbers on left side (words) will equal to the number on right side (result).
Return True if the equation is solvable otherwise return False.

Example 1:

Input: words = ["SEND","MORE"], result = "MONEY"
Output: true
Explanation: Map 'S'-> 9, 'E'->5, 'N'->6, 'D'->7, 'M'->1, 'O'->0, 'R'->8, 'Y'->'2'
Such that: "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652
Example 2:

Input: words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
Output: true
Explanation: Map 'S'-> 6, 'I'->5, 'X'->0, 'E'->8, 'V'->7, 'N'->2, 'T'->1, 'W'->'3', 'Y'->4
Such that: "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214
Example 3:

Input: words = ["THIS","IS","TOO"], result = "FUNNY"
Output: true
Example 4:

Input: words = ["LEET","CODE"], result = "POINT"
Output: false


Constraints:

2 <= words.length <= 5
1 <= words[i].length, results.length <= 7
words[i], result contains only upper case English letters.
Number of different characters used on the expression is at most 10.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    bool dfs(int curCharIdx, int markOfUsedDigits, int sum, 
        vector<bool>& isLeadingDigit, vector<int>& basicSumOfChar, vector<char>& charVec) {
        if (curCharIdx >= charVec.size())
            return sum == 0;
        char curChar = charVec[curCharIdx];
        for (int digit = 0; digit < 10; ++digit) {
            if ((markOfUsedDigits >> digit) & 1)
                continue;
            if (digit == 0 && isLeadingDigit[curChar - 'A'])
                continue;
            bool ret = dfs(curCharIdx + 1, markOfUsedDigits | (1 << digit), sum + digit * basicSumOfChar[curChar - 'A'], 
                isLeadingDigit, basicSumOfChar, charVec);
            if (ret)
                return true;
        }
        return false;
    }
    bool isSolvable(vector<string>& words, string result) {
        // 1, 10, 100, ...
        vector<int> ten(8, 1);
        for (int i = 1; i < 8; ++i)
            ten[i] = ten[i - 1] * 10;

        int n = words.size();
        vector<bool> isLeadingDigit(26, 0);
        vector<int> basicSumOfChar(26, 0);  // sum of A/B/...
        set<char> charSet;
        for (int i = 0; i < n; ++i) {
            int wordLen = words[i].size();
            for (int j = 0; j < wordLen; ++j) {
                char ch = words[i][j];
                charSet.insert(ch);
                basicSumOfChar[ch - 'A'] += ten[wordLen - 1 - j];
            }
            if (wordLen > 1)
                isLeadingDigit[words[i][0] - 'A'] = true;
        }
        
        int wordLen = result.size();
        for (int j = 0; j < wordLen; ++j) {
            char ch = result[j];
            charSet.insert(ch);
            basicSumOfChar[ch - 'A'] -= ten[wordLen - 1 - j];
        }
        if (wordLen > 1)
            isLeadingDigit[result[0] - 'A'] = true;

        vector<char> charVec;
        charVec.assign(charSet.begin(), charSet.end());
        return dfs(0, 0, 0, isLeadingDigit, basicSumOfChar, charVec);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
