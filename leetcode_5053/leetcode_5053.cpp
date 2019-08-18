// leetcode_5053.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Given an N x N grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized and return the distance.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

If no land or water exists in the grid, return -1.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {	
public:
	int maxDistance(vector<vector<int>>& grid) {
		int N = grid.size();
		vector<vector<int>> dp(N, vector<int>(N, -1));
		queue<pair<int, int>> q;

		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++) 
				if (grid[i][j] == 1) {
					dp[i][j] = 0;
					q.emplace(make_pair(i, j));
				}

		vector<pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
		while (!q.empty()) {
			pair<int, int> center = q.front();
			q.pop();
			for (pair<int, int>& direction: directions) {
				int _i = center.first + direction.first, _j = center.second + direction.second;
				if (_i >= 0 && _i < N && _j >= 0 && _j < N) {
					if (~dp[_i][_j]) continue;
					dp[_i][_j] = dp[center.first][center.second] + 1;
					q.emplace(make_pair(_i, _j));
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (dp[i][j] > ans)
					ans = dp[i][j];
		return (ans == 0) ? -1 : ans;
	}
};


int main()
{
    std::cout << "Hello World!\n";
}