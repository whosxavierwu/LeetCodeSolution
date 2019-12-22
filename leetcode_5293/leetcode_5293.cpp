// leetcode_5293.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://leetcode.com/contest/weekly-contest-168/problems/maximum-number-of-occurrences-of-a-substring/
/*
Given a string s, return the maximum number of ocurrences of any substring under the following rules:

The number of unique characters in the substring must be less than or equal to maxLetters.
The substring size must be between minSize and maxSize inclusive.


Example 1:

Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
Output: 2
Explanation: Substring "aab" has 2 ocurrences in the original string.
It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).
Example 2:

Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
Output: 2
Explanation: Substring "aaa" occur 2 times in the string. It can overlap.
Example 3:

Input: s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
Output: 3
Example 4:

Input: s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
Output: 0


Constraints:

1 <= s.length <= 10^5
1 <= maxLetters <= 26
1 <= minSize <= maxSize <= min(26, s.length)
s only contains lowercase English letters.
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int>mmap;
        int n = s.size();
        for (int len = minSize; len <= maxSize; ++len) {
            unordered_map<char, int> cntMap;
            int ncnt = 0;
            for (int i = 0; i < len - 1; ++i) {
                if (!cntMap[s[i]]++) {
                    ncnt++;
                }
            }
            for (int i = len - 1; i < n; ++i) {
                if (!cntMap[s[i]]++) {
                    ncnt++;
                }
                if (ncnt <= maxLetters)
                    mmap[s.substr(i - len + 1, len)]++;
                if (!--cntMap[s[i - len + 1]])
                    ncnt--;
            }
        }
        int result = 0;
        for (auto p : mmap)
            if (p.second > result)
                result = p.second;
        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
