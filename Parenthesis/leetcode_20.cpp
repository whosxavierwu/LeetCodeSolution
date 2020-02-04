// leetcode_20.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/valid-parentheses/
/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		// v1: faster than 100.00%
		stack<char> sta;
		for (char c : s) {
			if (c == '(' || c == '{' || c == '[')
				sta.push(c);
			else {
				if (sta.empty())
					return false;
				if ((sta.top() == '(' && c == ')') 
					|| (sta.top() == '{' && c == '}') 
					|| (sta.top() == '[' && c == ']'))
					sta.pop();
				else 
					return false;
			}
		}
		return sta.empty();
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
