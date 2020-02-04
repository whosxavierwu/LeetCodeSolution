// leetcode_221.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/maximal-square/
/*
Given a 2D binary matrix filled with 0's and 1's, 
find the largest square containing only 1's and return its area.

Input:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		// v1: 20 ms, faster than 80.71%
		//int N = matrix.size();
		//if (N == 0) return 0;
		//int M = matrix[0].size();
		//vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
		//int maxSquareLen = 0;
		//for (int i = 1; i <= N; ++i) {
		//	for (int j = 1; j <= M; ++j) {
		//		if (matrix[i - 1][j - 1] == '1') {
		//			dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
		//			maxSquareLen = max(maxSquareLen, dp[i][j]);
		//		}
		//	}
		//}
		//return maxSquareLen * maxSquareLen;

		// v2  20 ms, faster than 80.71% 
		int N = matrix.size();
		if (N == 0) return 0;
		int M = matrix[0].size();
		vector<int> dp(M + 1, 0);
		int maxLen = 0, prev = 0;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				int tmp = dp[j];
				if (matrix[i - 1][j - 1] == '1') {
					dp[j] = min(min(dp[j - 1], prev), dp[j]) + 1;
					maxLen = max(maxLen, dp[j]);
				}
				else {
					dp[j] = 0;
				}
				prev = tmp;
			}
		}
		return maxLen * maxLen;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
