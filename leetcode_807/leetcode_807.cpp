// leetcode_807.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
		// faster than 81.43%
		int len = grid.size();
		vector<int> maxOfRow(len, INT_MIN);  
		vector<int> maxOfCol(len, INT_MIN);
		for (int r = 0; r < len; ++r) {
			for (int c = 0; c < len; ++c) {
				if (grid[r][c] > maxOfRow[r])
					maxOfRow[r] = grid[r][c];
				if (grid[r][c] > maxOfCol[c])
					maxOfCol[c] = grid[r][c];
			}
		}
		int count = 0;
		for (int r = 0; r < len; ++r) {
			for (int c = 0; c < len; ++c) {
				count += fmin(maxOfRow[r], maxOfCol[c]) - grid[r][c];
			}
		}
		return count;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
