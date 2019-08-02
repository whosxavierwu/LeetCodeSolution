// leetcode_980.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/unique-paths-iii/
/*
On a 2-dimensional grid, there are 4 types of squares:

1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks 
from the starting square to the ending square, 
that walk over every non-obstacle square exactly once.

1 <= grid.length * grid[0].length <= 20
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	//// v1: brute-force TLE
	//int uniquePathsIII(vector<vector<int>>& grid) {
	//	int N = grid.size(), M = grid[0].size();
	//	pair<int, int> start, end;
	//	// first pass to find out start & end point, and stores other points, check reachablity
	//	vector<pair<int, int>> points;
	//	for (int i = 0; i < N; ++i) {
	//		for (int j = 0; j < M; ++j) {
	//			if (grid[i][j] == -1) continue;
	//			pair<int, int> cur(i, j);
	//			int neighbors = int((i > 0) && grid[i - 1][j] != -1)
	//				+ int((j > 0) && grid[i][j - 1] != -1)
	//				+ int((i < N - 1) && grid[i + 1][j] != -1)
	//				+ int((j < M - 1) && grid[i][j + 1] != -1);
	//			if (grid[i][j] == 1) {
	//				if (neighbors < 1) return 0;
	//				start = cur;
	//			}
	//			else if (grid[i][j] == 2) {
	//				if (neighbors < 1) return 0;
	//				end = cur;
	//			}
	//			else {
	//				if (neighbors < 2) return 0;
	//				points.push_back(cur);
	//			}
	//		}
	//	}
	//	int count = 0;
	//	do {
	//		pair<int, int> prev = start;
	//		bool hit = true;
	//		for (pair<int, int> cur : points) {
	//			if (abs(cur.first - prev.first) + abs(cur.second - prev.second) > 1) {
	//				hit = false;
	//				break;
	//			}
	//			prev = cur;
	//		}
	//		if (abs(end.first - prev.first) + abs(end.second - prev.second) > 1)
	//			hit = false;
	//		if (hit) ++count;
	//	} while (next_permutation(points.begin(), points.end()));
	//	return count;
	//}

	// v2  faster than 82.29%, less than 86.67%
	int uniquePathsIII(vector<vector<int>>& grid, pair<int, int>& end, pair<int, int>& cur, int& len) {
		if (cur.first == end.first && cur.second == end.second) {
			return (len <= 0);
		}
		
		int result = 0;
		pair<int, int> next;
		int tmp = 0;
		
		int curType = grid[cur.first][cur.second];
		grid[cur.first][cur.second] = -1;
		--len;
		// go up
		if (cur.first > 0) {
			next = make_pair(cur.first - 1, cur.second);
			tmp = grid[next.first][next.second];
			if (tmp != -1) {
				grid[next.first][next.second] = 1;
				result += uniquePathsIII(grid, end, next, len);
				grid[next.first][next.second] = tmp;
			}
		}
		// go down
		if (cur.first < grid.size() - 1) {
			next = make_pair(cur.first + 1, cur.second);
			tmp = grid[next.first][next.second];
			if (tmp != -1) {
				grid[next.first][next.second] = 1;
				result += uniquePathsIII(grid, end, next, len);
				grid[next.first][next.second] = tmp;
			}
		}
		// go left
		if (cur.second > 0) {
			next = make_pair(cur.first, cur.second - 1);
			tmp = grid[next.first][next.second];
			if (tmp != -1) {
				grid[next.first][next.second] = 1;
				result += uniquePathsIII(grid, end, next, len);
				grid[next.first][next.second] = tmp;
			}
		}
		// go right
		if (cur.second < grid[0].size() - 1) {
			next = make_pair(cur.first, cur.second + 1);
			tmp = grid[next.first][next.second];
			if (tmp != -1) {
				grid[next.first][next.second] = 1;
				result += uniquePathsIII(grid, end, next, len);
				grid[next.first][next.second] = tmp;
			}
		}
		
		++len;
		grid[cur.first][cur.second] = curType;

		return result;
	}
	int uniquePathsIII(vector<vector<int>>& grid) {
		int N = grid.size(), M = grid[0].size();
		pair<int, int> start, end;
		// first pass to find out start & end point, and stores other points, check reachablity
		int len = 0;  
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (grid[i][j] == -1) continue;
				pair<int, int> cur(i, j);
				int neighbors = int((i > 0) && grid[i - 1][j] != -1)
					+ int((j > 0) && grid[i][j - 1] != -1)
					+ int((i < N - 1) && grid[i + 1][j] != -1)
					+ int((j < M - 1) && grid[i][j + 1] != -1);
				if (grid[i][j] == 1) {
					if (neighbors < 1) return 0;
					start = cur;
				}
				else if (grid[i][j] == 2) {
					if (neighbors < 1) return 0;
					end = cur;
				}
				else {
					if (neighbors < 2) return 0;
					++len;
				}
			}
		}
		// len+1 because we need to count start
		++len;
		return uniquePathsIII(grid, end, start, len);
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> grid = { {1,0,0,0},{0,0,0,0},{0,0,2,-1} };
	int result = sol.uniquePathsIII(grid);
	cout << result << endl;
	return 0;
}

