// leetcode_63.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/unique-paths-ii/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		// v1: faster than 77.99%, less than 98.32% 
		if (obstacleGrid[0][0] != 0) return 0;
		int n = obstacleGrid.size();
		int m = obstacleGrid[0].size();
		vector<long> tmpRow(m, 0);
		tmpRow[0] = 1;
		for (int r = 0; r < n; ++r) {
			tmpRow[0] = (obstacleGrid[r][0] != 0) ? 0 : tmpRow[0];
			for (int c = 1; c < m; ++c) {
				tmpRow[c] = (obstacleGrid[r][c] != 0) ? 0 : (tmpRow[c] + tmpRow[c - 1]);
			}
		}
		return tmpRow[m - 1];
	}
};
int main()
{
	Solution sol;
	vector<vector<int>> grid = { {0, 0}, {1, 1}, {0, 0} };
	//vector<vector<int>> grid = { {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };
	int result = sol.uniquePathsWithObstacles(grid);
	cout << result << endl;
	return 0;
}
