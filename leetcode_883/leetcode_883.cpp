// leetcode_883.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/projection-area-of-3d-shapes/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int projectionArea(vector<vector<int>>& grid) {
		// v1: faster than 98.93% 
		int N = grid.size();
		int result = 0;
		int max = 0;
		for (int i = 0; i < N; ++i) {
			int rMax = 0;
			int cMax = 0;
			for (int j = 0; j < N; ++j) {
				if (grid[i][j] > 0)
					result++;
				if (grid[i][j] > rMax)
					rMax = grid[i][j];
				if (grid[j][i] > cMax)
					cMax = grid[j][i];
			}
			result += rMax + cMax;
		}
		return result;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
