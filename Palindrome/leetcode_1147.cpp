// leetcode_1147.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/longest-chunked-palindrome-decomposition/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	// v1: faster than 66.67% 
	int longestDecomposition(string& text, int left, int right) {
		if (left > right) return 0;
		int t = 1;
		while (true) {
			if (text.substr(left, t) == text.substr(right - t + 1, t))
				break;
			++t;
		}
		if (left == right - t + 1) return 1;
		return 2 + longestDecomposition(text, left + t, right - t);
	}
	int longestDecomposition(string text) {
		return longestDecomposition(text, 0, text.length() - 1);
	}
};
//
//int main()
//{
//	Solution sol;
//	string text;
//	int result; 
//	text = "ghiabcdefhelloadamhelloabcdefghi";
//	result = sol.longestDecomposition(text);
//	cout << result << endl;
//	text = "merchant";
//	result = sol.longestDecomposition(text);
//	cout << result << endl;
//	text = "antaprezatepzapreanta";
//	result = sol.longestDecomposition(text);
//	cout << result << endl;
//	text = "aaa";
//	result = sol.longestDecomposition(text);
//	cout << result << endl;
//	text = "elvtoelvto";
//	result = sol.longestDecomposition(text);
//	cout << result << endl;
//}
