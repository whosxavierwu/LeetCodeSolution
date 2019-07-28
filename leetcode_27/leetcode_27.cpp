// leetcode_27.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	void backtrack(vector<string>& result, string cur, int open, int close, int max) {
		if (cur.length() == max * 2) {
			result.push_back(cur);
		}
		else {
			if (open < max)
				backtrack(result, cur + "(", open + 1, close, max);
			if (close < open)
				backtrack(result, cur + ")", open, close + 1, max);
		}
	}
	vector<string> generateParenthesis(int n) {
		// v1: backtracking faster than 61.00%
		//vector<string> result;
		//backtrack(result, "", 0, 0, n);
		//return result;

		// v2: closure number faster than 61.00%
		vector<string> result;
		if (n == 0)
			result.push_back("");
		else {
			for (int c = 0; c < n; ++c) {
				for (string left : generateParenthesis(c)) {
					for (string right : generateParenthesis(n - 1 - c)) {
						result.push_back("(" + left + ")" + right);
					}
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
