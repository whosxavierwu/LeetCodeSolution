// leetcode_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // v1: 8 ms, faster than 94.41% 
        //vector<int> idxVec(256, -1);
        //int maxLen = 0, start = -1;
        //for (int i = 0; i < s.size(); ++i) {
        //    start = max(start, idxVec[s[i]]);
        //    idxVec[s[i]] = i;
        //    maxLen = max(maxLen, i - start);
        //}
        //return maxLen;

        // v2:  0 ms, faster than 100.00%
        vector<int> vec(128, 0);
        int begin = 0, end = 0, len = 0, counter = 0;
        while (end < s.size()) {
            if (vec[s[end]] > 0)
                counter++;
            vec[s[end]]++;
            end++;
            while (counter > 0) {
                if (vec[s[begin]] > 1)
                    counter--;
                vec[s[begin]]--;
                begin++;
            }
            len = max(len, end - begin);
        }
        return len;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
