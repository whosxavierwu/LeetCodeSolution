// leetcode_1351.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
/*
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

Example 1:

Input: grid = [
    [4,   3,  2,- 1],
    [3,   2,  1, -1],
    [1,   1, -1, -2],
    [-1, -1, -2, -3]
]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNeg(const vector<vector<int>>& grid, int rStart, int rEnd, int cStart, int cEnd) {
        if (rStart > rEnd || cStart > cEnd) {
            return 0;
        }
        if (grid[rStart][cStart] < 0) {
            return (rEnd - rStart + 1) * (cEnd - cStart + 1);
        }
        if (grid[rEnd][cEnd] >= 0) {
            return 0;
        }
        int rMid = rStart + (rEnd - rStart) / 2;
        int cMid = cStart + (cEnd - cStart) / 2;
        int result = 0;
        if (grid[rMid][cMid] >= 0) {
            // up-left cannot be negative
            result += countNeg(grid, rMid + 1, rEnd, cStart, cEnd);  // down
            result += countNeg(grid, rStart, rMid, cMid + 1, cEnd);  // up-right
        } else {
            // down-right must be negative
            result += (rEnd - rMid + 1) * (cEnd - cMid + 1);  // down-right
            result += countNeg(grid, rStart, rMid - 1, cStart, cEnd);  // up
            result += countNeg(grid, rMid, rEnd, cStart, cMid - 1);  // down-left
        }
        return result;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        return countNeg(grid, 0, rows - 1, 0, cols - 1);
    }
};


int main()
{
    std::cout << "Hello World!\n";
}
