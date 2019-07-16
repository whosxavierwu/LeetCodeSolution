// leetcode_1108.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/defanging-an-ip-address/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string defangIPaddr(string address) {
		string res = "";
		for (char c : address)
			if (c == '.')
				res += "[.]";
			else
				res += c;
		return res;
	}
};

int main()
{
	Solution sol;
	string res = sol.defangIPaddr("1.1.1.1");
	cout << res << endl;
	return 0;
}

