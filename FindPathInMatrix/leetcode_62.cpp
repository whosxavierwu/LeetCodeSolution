// leetcode_62.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://leetcode.com/problems/unique-paths/
/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		// v1: TLE
		//if (m == 1 || n == 1) return 1;
		//return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);

		// v2 faster than 60.14%
		//if (m == 1 || n == 1) return 1;
		//vector<vector<int>> matrix(n, vector<int>(m, 1));
		//for (int r = 1; r < n; ++r) {
		//	for (int c = 1; c < m; ++c) {
		//		matrix[r][c] = matrix[r - 1][c] + matrix[r][c - 1];
		//	}
		//}
		//return matrix[n - 1][m - 1];

		// v3 faster than 100.00%, less than 48.68%
		//if (m == 1 || n == 1) return 1;
		//vector<int> prevRow(m, 1);
		//vector<int> curRow(m, 1);
		//for (int r = 1; r < n; ++r) {
		//	curRow[0] = 1;
		//	for (int c = 1; c < m; ++c)
		//		curRow[c] = prevRow[c] + curRow[c - 1];
		//	prevRow = curRow;
		//}
		//return curRow[m - 1];

		// v4 faster than 60.14%, less than 75.25%
		//if (m == 1 || n == 1) return 1;
		//vector<int> prevRow(m, 1);
		//for (int r = 1; r < n; ++r) {
		//	int prevCol = 1;
		//	for (int c = 1; c < m; ++c) {
		//		prevCol += prevRow[c];
		//		prevRow[c] = prevCol;
		//	}
		//}
		//return prevRow[m - 1];

		// v5: faster than 100.00%, less than 67.75% 
		if (m == 1 || n == 1) return 1;
		vector<int> prevRow(m, 1);
		for (int r = 1; r < n; ++r) 
			for (int c = 1; c < m; ++c) 
				prevRow[c] += prevRow[c-1];
		return prevRow[m - 1];
	}
};
int main()
{
    std::cout << "Hello World!\n";
}

