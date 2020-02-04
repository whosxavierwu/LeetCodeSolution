// leetcode_200.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/number-of-islands/
/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.
*/
#include <iostream>
#include <vector>
using namespace std;

// v1: faster than 99.93% 
class Solution {
public:
	void DFSErase(vector<vector<char>>& grid, const int& i, const int& j) {
		// dfs erase lands
		if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] != '1') return;
		grid[i][j] = '0';
		DFSErase(grid, i - 1, j);
		DFSErase(grid, i + 1, j);
		DFSErase(grid, i, j - 1);
		DFSErase(grid, i, j + 1);
	}
	int numIslands(vector<vector<char>>& grid) {
		int cnt = 0;
		int N = grid.size(); 
		if (N == 0) return 0;
		int M = grid[0].size();
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (grid[i][j] == '1') {
					DFSErase(grid, i, j);
					cnt++;
				}
			}
		}
		return cnt;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
