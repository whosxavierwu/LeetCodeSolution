// leetcode_5274.cpp : This file contains the 'main' function. Program execution begins and ends there.
// todo https://leetcode.com/contest/weekly-contest-164/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/

#include <iostream>

class Solution {
public:
	int numWays(int steps, int arrLen) {

	}
};

//const int MOD = 1e9 + 7;
//
//class Solution {
//public:
//	int numWays(int steps, int arrLen) {
//		arrLen = min(arrLen, steps);
//		vector<vector<long long>> dp(steps + 1, vector<long long>(arrLen, 0));
//		dp[0][0] = 1;
//
//		for (int s = 0; s < steps; s++)
//			for (int i = 0; i < arrLen; i++) {
//				if (i > 0) {
//					dp[s + 1][i - 1] += dp[s][i];
//					dp[s + 1][i - 1] %= MOD;
//				}
//
//				if (i + 1 < arrLen) {
//					dp[s + 1][i + 1] += dp[s][i];
//					dp[s + 1][i + 1] %= MOD;
//				}
//
//				dp[s + 1][i] += dp[s][i];
//				dp[s + 1][i] %= MOD;
//			}
//
//		return dp[steps][0];
//	}
//};

int main()
{
    std::cout << "Hello World!\n";
}
