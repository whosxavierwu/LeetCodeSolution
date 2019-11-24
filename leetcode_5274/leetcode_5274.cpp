// leetcode_5274.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-164/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int numWays(int steps, int arrLen) {
		const int MOD = 1e9 + 7;
		if (steps < arrLen) arrLen = steps;
		// [i][j] means take exactly i steps to get to the position j
		vector<vector<long long>> waysToSomePlace(steps + 1, vector<long long>(arrLen, 0));
		waysToSomePlace[0][0] = 1;
		for (int step = 0; step < steps; ++step) {
			for (int i = 0; i < arrLen; ++i) {
				// go left
				if (i > 0) {
					waysToSomePlace[step + 1][i - 1] += waysToSomePlace[step][i];
					waysToSomePlace[step + 1][i - 1] %= MOD;
				}
				// go right
				if (i + 1 < arrLen) {
					waysToSomePlace[step + 1][i + 1] += waysToSomePlace[step][i];
					waysToSomePlace[step + 1][i + 1] %= MOD;
				}
				// stay
				waysToSomePlace[step + 1][i] += waysToSomePlace[step][i];
				waysToSomePlace[step + 1][i] %= MOD;
			}
		}
		return waysToSomePlace[steps][0];
	}
};


int main()
{
    std::cout << "Hello World!\n";
}
