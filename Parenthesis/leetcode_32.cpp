// leetcode_32.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/longest-valid-parentheses/
/*
Given a string containing just the characters '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		// v1: faster than 5.03%, less than 96.43%
		//int start = 0, end = s.length() - 1;
		//while (start < s.length() && s[start] == ')') ++start;
		//while (end >= 0 && s[end] == '(') --end;
		//if (start >= end) return 0;
		//int maxLen = 0;
		//for (int i = start; i <= end; ++i) {
		//	if (s[i] == ')') continue;
		//	int leftCnt = 1, rightCnt = 0;
		//	for (int j = i + 1; j <= end; ++j) {
		//		if (s[j] == '(') {
		//			++leftCnt;
		//		}
		//		else {
		//			++rightCnt;
		//			if (rightCnt == leftCnt) {
		//				maxLen = max(maxLen, 2 * leftCnt);
		//			}
		//			else if (rightCnt > leftCnt) {
		//				leftCnt = 0; 
		//				rightCnt = 0;
		//			}
		//		}
		//	}
		//}
		//return maxLen;

		// v2: faster than 95.95%, less than 57.14%
		int len = s.length();
		vector<int> dp(len);
		int maxLen = 0;
		for (int i = 1; i < len; ++i) {
			if (s[i] == ')') {
				if (s[i - 1] == '(')
					dp[i] = (i >= 2 ? dp[i - 2]: 0) + 2;
				else {
					int prevStrEnd = i - dp[i - 1] - 1;
					if (prevStrEnd >= 0 && s[prevStrEnd] == '(')  // (...)((...))
						dp[i] = (prevStrEnd > 0 ? dp[prevStrEnd - 1] : 0) + dp[i - 1] + 2;
				}
				maxLen = max(maxLen, dp[i]);
			}
		}
		return maxLen;

		// v3: faster than 59.56%, less than 100.00% 
		//int leftCount = 0, rightCount = 0, maxLen = 0;
		//int len = s.length();
		//for (char& c : s) {
		//	(c == '(') ? ++leftCount : ++rightCount;
		//	if (leftCount == rightCount)
		//		maxLen = max(maxLen, 2 * rightCount);
		//	else if (leftCount <= rightCount)
		//		leftCount = rightCount = 0;
		//}
		//leftCount = rightCount = 0;
		//for (int i = len - 1; i >= 0; --i) {
		//	(s[i] == '(') ? ++leftCount : ++rightCount;
		//	if (leftCount == rightCount)
		//		maxLen = max(maxLen, 2 * leftCount);
		//	else if (leftCount >= rightCount)
		//		leftCount = rightCount = 0;
		//}
		//return maxLen;
	}
};


int main()
{
	Solution sol;
	string s = "";
	//s = "(()";
	//cout << sol.longestValidParentheses(s) << endl;
	//s = ")()())";
	//cout << sol.longestValidParentheses(s) << endl;
	//s = "(())()(()((";
	//cout << sol.longestValidParentheses(s) << endl;
	//s = "(()(((()";
	//cout << sol.longestValidParentheses(s) << endl;
	s = "(()()";
	cout << sol.longestValidParentheses(s) << endl;
	return 0;
}
