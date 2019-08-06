// leetcode_394.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/decode-string/
/*
Given an encoded string, return its decoded string.

The encoding rule is: 
k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. 
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; 
No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits 
and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/
#include <iostream>
#include <string>
using namespace std;

// v1: faster than 100.00% , less than 88.72% 
class Solution {
public:
	string decodeString(string& s, int left, int right, int times) {
		if (left > right) return "";
		if (left == right) return string(times, s[left]);
		string singleStr = "";
		// part 1: no repeation
		int i = left; 
		while (i <= right && !isdigit(s[i])) ++i;
		singleStr += s.substr(left, i - left);
		// part 2: has repeation
		if (i <= right) {
			// find out the numbers
			int lDigit = i;
			while (isdigit(s[i])) ++i;
			int leftParenthesis = i;
			int tmpTimes = stoi(s.substr(lDigit, leftParenthesis - lDigit));
			// find out the right parenthesis
			int lCnt = 0, rCnt = 0;
			while (i <= right) {
				if (s[i] == '[') ++lCnt;
				else if (s[i] == ']') ++rCnt;
				if (lCnt == rCnt && lCnt > 0)
					break;
				++i;
			}
			int rightParenthesis = i;
			// add string between left & right parenthesis
			singleStr += decodeString(s, leftParenthesis + 1, rightParenthesis - 1, tmpTimes);
			// add the rest
			singleStr += decodeString(s, rightParenthesis + 1, right, 1);
		}
		// repeat result
		string result = "";
		for (int i = 0; i < times; ++i)
			result += singleStr;
		return result;
	}
	string decodeString(string s) {
		return decodeString(s, 0, s.length() - 1, 1);
	}
};
int main()
{
	Solution sol;
	string s;
	s = "3[a]2[bc]";
	cout << sol.decodeString(s) << endl;
	s = "3[a2[c]]";
	cout << sol.decodeString(s) << endl;
	s = "2[abc]3[cd]ef";
	cout << sol.decodeString(s) << endl;
	return 0;
}
