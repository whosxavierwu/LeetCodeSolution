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
using namespace std;

class Solution {
public:
	
	int insertR2N(int n, int r) {
		// insert r numbers to length n (n+1 slots)
		if (n == 0) return 1;
		if (n == 1) return r + 1;
		if (r == 1) return n + 1;
		// put r numbers to n+1 slots
		// f(n+1, r) = f(n, r) + f(n, r-1) + ... + f(n, 0)
		vector<int> f(r + 1, 1);
		for (int i = 2; i <= n + 1; ++i) {
			for (int j = 1; j <= r; ++j) {
				f[j] += f[j - 1];
			}
		}
		return f[r];
	}
	int numTilePossibilities(string tiles) {
		vector<int> letterCount(26);
		for (char& c : tiles) letterCount[c - 'A'] += 1;
		// number of results in length i (1 to n)
		vector<int> numOfPermuteGivenLen(tiles.length() + 1); 
		
		int prevMaxLen = 0;
		for (int& curLetterCount : letterCount) {
			for (int numOfLettersToInsert = 1; numOfLettersToInsert <= curLetterCount; ++numOfLettersToInsert) {
				for (int prevLen = 0; prevLen <= prevMaxLen; ++prevLen) {
					numOfPermuteGivenLen[prevLen + numOfLettersToInsert] += insertR2N(prevLen, numOfLettersToInsert);
				}
			}
			prevMaxLen += curLetterCount;
		}
		int result = 0;
		for (int& a : numOfPermuteGivenLen) {
			result += a;
		}
		return result;
	}
};

int main()
{
	Solution sol;
	string s;
	//s = "AAB";
	//cout << sol.numTilePossibilities(s) << endl;
	// todo 到C的时候就出问题了
	s = "AAABBC";
	cout << sol.numTilePossibilities(s) << endl;

}
