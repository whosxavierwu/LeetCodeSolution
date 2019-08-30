// leetcode_557.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/reverse-words-in-a-string-iii/
/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		// v1: 60 ms, faster than 8.74%
		//int pos = 0;
		//string result = "";
		//while (pos != s.npos) {
		//	int prev = pos > 0 ? pos : -1;
		//	pos = s.find(' ', prev + 1);
		//	string tmp = s.substr(prev + 1, pos - prev -1);
		//	reverse(tmp.begin(), tmp.end());
		//	result = result + tmp + " ";
		//}
		//result.pop_back();
		//return result;

		// v2: 24 ms, faster than 57.95% 
		int len = s.length();
		int prev = -1;
		string result = "";
		for (int i = 0; i < len; ++i) {
			if (s[i] == ' ') {
				for (int j = i - 1; j > prev; --j)
					result.push_back(s[j]);
				result.push_back(' ');
				prev = i;
			}
		}
		for (int j = len - 1; j > prev; --j)
			result.push_back(s[j]);
		return result;
	}
};
int main()
{
	Solution sol;
	cout << sol.reverseWords("Let's take LeetCode contest") << "#" << endl;
}
