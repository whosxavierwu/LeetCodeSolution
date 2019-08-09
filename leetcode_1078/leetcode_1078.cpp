// leetcode_1078.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/occurrences-after-bigram/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> findOcurrences(string text, string first, string second) {
		// faster than 100.00% 
		string target = first + " " + second + " ";
		int pos = -1;
		vector<string> result;
		while (true) {
			pos = text.find(target, pos + 1);
			if (pos == text.npos)
				break;
			int nextWordPos = pos + target.length();
			int spacePos = text.find(' ', nextWordPos);
			string tmp = text.substr(nextWordPos, spacePos - nextWordPos);
			result.push_back(tmp);
		}
		return result;
	}
};

int main()
{
	Solution sol;
	string text = "alice is a good girl she is a good student";
	string first = "a";
	string second = "good";
	vector<string> result = sol.findOcurrences(text, first, second);
	for (string& res : result) {
		cout << res << endl;
	}
}
