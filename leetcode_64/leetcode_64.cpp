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

class Solution {
public:
	void findPath(vector<vector<int>>& grid, pair<int, int> cur, int& minSum, int& curSum) {
		if ((cur.first == grid.size()-1) && (cur.second == grid[0].size()-1)) {
			curSum += grid[cur.first][cur.second];
			if (curSum < minSum) minSum = curSum;
		}
		else {
			curSum += grid[cur.first][cur.second];
			if (cur.first + 1 < grid.size())
				findPath(grid, make_pair(cur.first + 1, cur.second), minSum, curSum);
			if (cur.second + 1 < grid[0].size())
				findPath(grid, make_pair(cur.first, cur.second + 1), minSum, curSum);
			curSum -= grid[cur.first][cur.second];
		}
	}
	int minPathSum(vector<vector<int>>& grid) {
		int minSum = INT_MAX, curSum = 0;
		findPath(grid, make_pair(0, 0), minSum, curSum);
		return minSum;
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
