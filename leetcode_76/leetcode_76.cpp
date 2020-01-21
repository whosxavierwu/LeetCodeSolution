// leetcode_76.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/minimum-window-substring/
/*
Given a string S and a string T, 
find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        //// v1:  8 ms, faster than 97.45% 
        //vector<int> vec(128, 0);
        //for (char ch : t) vec[ch]++;
        //int remaining = t.length();
        //int left = 0, right = 0;
        //int minStart = 0, minLen = INT_MAX;
        //while (right < s.length()) {
        //    // move right
        //    if (--vec[s[right++]] >= 0) {
        //        --remaining;
        //    }
        //    while (remaining == 0) {
        //        if (right - left < minLen) {
        //            minLen = right - left;
        //            minStart = left;
        //        }
        //        // move left
        //        if (++vec[s[left++]] > 0) {
        //            ++remaining;
        //        }
        //    }
        //}
        //return minLen < INT_MAX ? s.substr(minStart, minLen) : "";

        // v2  8 ms, faster than 97.33%
        //vector<int> vec(128, 0);
        //for (char ch : t)
        //    vec[ch]++;
        //int cnt = t.size();
        //int left = 0, right = 0;
        //int head = 0, len = INT_MAX;
        //while (right < s.size()) {
        //    if (vec[s[right++]]-- > 0)
        //        cnt--;
        //    while (cnt == 0) {
        //        if (right - left < len) {
        //            len = right - left;
        //            head = left;
        //        }
        //        if (vec[s[left++]]++ == 0)
        //            cnt++;
        //    }
        //}
        //return len == INT_MAX ? "" : s.substr(head, len);

        // v3  12 ms, faster than 83.62% 
        vector<int> countVec(128, 0);
        for (char ch : t)
            countVec[ch]++;
        int left = 0, right = 0, subStrHead = 0, subStrLen = INT_MAX;
        int remaining = t.size();
        while (right < s.size()) {
            // note: check if hit, before update right
            if (countVec[s[right]] > 0)
                remaining--;
            countVec[s[right]]--;
            right++;
            while (remaining == 0) {
                if (right - left < subStrLen) {
                    subStrLen = right - left;
                    subStrHead = left;
                }
                // note: update countVec, before check
                countVec[s[left]]++;
                if (countVec[s[left]] > 0)
                    remaining++;
                left++;
            }
        }
        return subStrLen == INT_MAX ? "" : s.substr(subStrHead, subStrLen);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
