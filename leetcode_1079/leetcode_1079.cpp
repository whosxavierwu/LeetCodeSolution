// leetcode_1079.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/letter-tile-possibilities/
/*
You have a set of tiles, 
where each tile has one letter tiles[i] printed on it.  
Return the number of possible non-empty sequences of letters you can make.
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// v1: https://leetcode.com/problems/letter-tile-possibilities/discuss/308387/c%2B%2B-0ms-8.5-MB-beats-100-(both-time-and-memory)-with-algo
// 4 ms, faster than 94.20%
class Solution {
	int factorial(int n) {
		int fact = 1; 
		for (int i = 2; i <= n; ++i)
			fact *= i;
		return fact;
	}
	int countDistinctPerm(string str) {
		int len = str.length();
		vector<int> freq(26);
		for (int i = 0; i < len; ++i) 
			if (str[i] >= 'A')
				freq[str[i] - 'A']++;
		int fact = 1;
		for (int i = 0; i < 26; ++i)
			fact *= factorial(freq[i]);
		return factorial(len) / fact;
	}
	void findComb(const string& tiles, string s, int i, int index, int& result) {
		if (index == s.length()) {
			result += countDistinctPerm(s);
			return;
		}
		int n = tiles.size();
		if (i >= n) return;
		s[index] = tiles[i];
		findComb(tiles, s, i + 1, index + 1, result);
		while (i < n - 1 && tiles[i] == tiles[i + 1]) ++i;
		findComb(tiles, s, i + 1, index, result);
	}
public:
	int numTilePossibilities(string tiles) {
		int result = 0;
		sort(tiles.begin(), tiles.end());
		for (int curNumOfTile = 1; curNumOfTile <= tiles.length(); ++curNumOfTile) {
			string s(curNumOfTile, '.');
			findComb(tiles, s, 0, 0, result);
		}
		return result;
	}
};

int main()
{
	Solution sol;
	string s;
	s = "AAB";
	cout << sol.numTilePossibilities(s) << endl;
	s = "AAABBC";
	cout << sol.numTilePossibilities(s) << endl;

}
