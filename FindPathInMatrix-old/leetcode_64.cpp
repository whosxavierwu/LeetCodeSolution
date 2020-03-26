// leetcode_64.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/minimum-path-sum/
/*
Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
*/
#include <iostream>
#include <vector>
using namespace std;

// v1: TLE
//class Solution {
//public:
//	void findPath(vector<vector<int>>& grid, pair<int, int> cur, int& minSum, int& curSum) {
//		curSum += grid[cur.first][cur.second];
//		if ((cur.first == grid.size()-1) && (cur.second == grid[0].size()-1)) {
//			if (curSum < minSum) minSum = curSum;
//		}
//		else {
//			if (cur.first + 1 < grid.size())
//				findPath(grid, make_pair(cur.first + 1, cur.second), minSum, curSum);
//			if (cur.second + 1 < grid[0].size())
//				findPath(grid, make_pair(cur.first, cur.second + 1), minSum, curSum);
//		}
//		curSum -= grid[cur.first][cur.second];
//	}
//	int minPathSum(vector<vector<int>>& grid) {
//		int minSum = INT_MAX, curSum = 0;
//		findPath(grid, make_pair(0, 0), minSum, curSum);
//		return minSum;
//	}
//};

// v2: faster than 88.38%, less than 91.07%
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int N = grid.size();
		int M = grid[0].size();
		vector<int> vec(M);
		vec[0] = grid[0][0];
		for (int j = 1; j < M; ++j) {
			vec[j] = vec[j - 1] + grid[0][j];
		}
		for (int i = 1; i < N; ++i) {
			vec[0] += grid[i][0];
			for (int j = 1; j < M; ++j) {
				vec[j] = fmin(vec[j], vec[j - 1]) + grid[i][j];
			}
		}
		return vec[M - 1];
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> grid = { {1,3,1},{1,5,1},{4,2,1} };
	int result = sol.minPathSum(grid);
	cout << result << endl;
	return 0;
}
