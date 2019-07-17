// leetcode_1021.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/remove-outermost-parentheses/
/*
S.length <= 10000
S[i] is "(" or ")"
S is a valid parentheses string
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string removeOuterParentheses(string S) {
		// v1: faster than 93.82% 
		string result = "";
		string tmp = "";
		int left = 0, right = 0;
		int prev = 0;
		for (char c : S) {
			if (c == '(') {
				if (left != 0)
					tmp += c;
				++left;
			}
			else {  // )
				++right;
				if (left == right) {
					result += tmp;
					tmp = "";
					left = 0; 
					right = 0;
				}
				else {
					tmp += c;
				}
			}
		}
		return result;
		// v2:
		string result = "";
		int left = 0, right = 0;
		for (char c : S) {
			if (c == '(') {
				if (left != 0)
					result += c;
				++left;
			}
			else {  // )
				++right;
				if (left == right) {
					left = 0;
					right = 0;
				}
				else {
					result += c;
				}
			}
		}
		return result;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

