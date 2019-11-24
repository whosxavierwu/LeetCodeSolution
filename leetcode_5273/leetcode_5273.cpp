// leetcode_5273.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-164/problems/search-suggestions-system/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
		sort(products.begin(), products.end());

		vector<vector<string>> result;
		
		int len = searchWord.size();
		for (int i = 1; i <= len; ++i) {
			vector<string> tmpResult = {};
			if (result.empty() || (!result.back().empty())) {
				string subWord = searchWord.substr(0, i);
				vector<string>::iterator iter = lower_bound(products.begin(), products.end(), subWord);
				
				for (int j = 0; j < 3; ++j) {
					if (iter + j == products.end())
						break;
					if ((iter + j)->substr(0, i) == subWord) {
						tmpResult.push_back(*(iter + j));
					}
				}
			}
			result.push_back(tmpResult);
		}
		return result;
	}
};

int main()
{
	Solution sol;
	vector<string> products = { "mobile","mouse","moneypot","monitor","mousepad" };
	string searchWord = "mouse";
	//vector<string> products = { "havana"};
	//string searchWord = "havana";
	vector<vector<string>> result = sol.suggestedProducts(products, searchWord);
	for (auto vec : result) {
		for (string s : vec) {
			cout << s << " ";
		}
		cout << endl;
	}
}
