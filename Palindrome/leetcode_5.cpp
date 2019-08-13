// leetcode_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/longest-palindromic-substring/
/*
Given a string s, find the longest palindromic substring in s. 
You may assume that the maximum length of s is 1000.

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Input: "cbbd"
Output: "bb"
*/

#include <iostream>
#include <string>
using namespace std;

// v1:  faster than 75.66%
class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		if (len == 1) return s;
		if (len == 2) return (s[0] == s[1]) ? s : string(1, s[0]);
		string longestStr = "";
		for (int center = 1; center < len-1; ++center) {
			int left = center - 1, right = center + 1;
			while (left >= 0 && s[left] == s[center])
				--left;
			while (right < len && s[right] == s[center])
				++right;
			while (left >= 0 && right < len && s[left] == s[right]) {
				--left;
				++right;
			}
			string tmp = s.substr(left + 1, right - left - 1);
			if (tmp.length() > longestStr.length())
				longestStr = tmp;
		}
		return longestStr;
	}
};
//
//int main()
//{
//	Solution sol;
//	cout << sol.longestPalindrome("babad") << endl;
//	cout << sol.longestPalindrome("cbbd") << endl;
//	cout << sol.longestPalindrome("babaddtattarrattatddetartrateedredividerb") << endl;
//	return 0;
//}
