// leetcode_174.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/dungeon-game/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// v1 faster than 99.19% 
//class Solution {
//public:
//	int calculateMinimumHP(vector<vector<int>>& dungeon) {
//		int N = dungeon.size();
//		int M = dungeon[0].size();
//		// the min hp needed at position (i, j)
//		vector<vector<int>> hp(N + 1, vector<int>(M + 1, INT_MAX));
//		// why 1? Because you have crossed the whold dungeon! 
//		hp[N][M - 1] = 1;
//		hp[N - 1][M] = 1;
//		for (int i = N - 1; i >= 0; --i) {
//			for (int j = M - 1; j >= 0; --j) {
//				int need = -dungeon[i][j] + min(hp[i + 1][j], hp[i][j + 1]);
//				hp[i][j] = need <= 0 ? 1 : need;
//			}
//		}
//		return hp[0][0];
//	}
//};

// v2 faster than 73.28%, less than 100.00% 
class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int N = dungeon.size();
		int M = dungeon[0].size();
		vector<int> dp(N + 1, INT_MAX);
		dp[N - 1] = 1;
		// for each col
		for (int j = M - 1; j >= 0; --j) {
			// go up
			for (int i = N - 1; i >= 0; --i) {
				dp[i] = -dungeon[i][j] + min(dp[i], dp[i + 1]);
				dp[i] = max(1, dp[i]);
			}
		}
		return dp[0];
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> matrix = {
		{1,-3,3},
		{0,-2,0},
		{-3,-3,-3} 
	};
	int result = sol.calculateMinimumHP(matrix);
	cout << result << endl;
	return 0;
}
