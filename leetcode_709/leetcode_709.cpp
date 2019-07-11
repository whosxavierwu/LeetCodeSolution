// leetcode_709.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  https://leetcode.com/problems/to-lower-case/
// Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string toLowerCase(string str) {
		// v1: not fast enough!!!
		//for (int i = 0; i < str.size(); ++i)
		//	if (str[i] >= 'A' && str[i] <= 'Z')
		//		str[i] = str[i] - 'A' + 'a';
		//return str;

		// v2: same as v1
		//string res = "";
		//for (int i = 0; i < str.size(); ++i)
		//	if (str[i] >= 'A' && str[i] <= 'Z')
		//		res.push_back(str[i] - 'A' + 'a');
		//	else
		//		res.push_back(str[i]);
		//return res;

		// v3: fastest version
		for (char& c : str)
			if (c >= 'A' && c <= 'Z')
				c = c - 'A' + 'a';
		return str;
	}
};

int main()
{
	Solution sol;
	cout << sol.toLowerCase("Hello, world") << endl;
}

