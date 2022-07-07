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
    int countNegatives1(vector<vector<int>>& grid) {  // 27ms
        int rows = grid.size();
        int cols = grid[0].size();
        return countNeg(grid, 0, rows - 1, 0, cols - 1);
    }
    int countNegatives2(vector<vector<int>>& grid) {  // 33ms
        int rows = grid.size();
        int cols = grid[0].size();
        int rStart = 0, cStart = 0;
        int rEnd = rows - 1, cEnd = cols - 1;
        int result = 0;
        while (rStart <= rEnd && cStart <= cEnd) {
            if (grid[rStart][cStart] < 0) {
                result = result + (rEnd - rStart + 1) * (cEnd - cStart + 1);
                break;
            }
            if (grid[rEnd][cEnd] >= 0) {
                break;
            }
            int r_first_neg = rStart;
            for (; r_first_neg <= rEnd; ++r_first_neg) {
                if (grid[r_first_neg][cEnd] < 0) {
                    break;
                }
            }
            int c_first_neg = cStart;
            for (; c_first_neg <= cEnd; ++c_first_neg) {
                if (grid[rEnd][c_first_neg] < 0) {
                    break;
                }
            }
            result = result + (rEnd - r_first_neg + 1) + (cEnd - c_first_neg + 1) - 1;
            rStart = r_first_neg;
            cStart = c_first_neg;
            rEnd--;
            cEnd--;
        }
        return result;
    }
    int countNegatives3(vector<vector<int>>& grid) {  // 33ms
        int rows = grid.size();
        int cols = grid[0].size();
        int rStart = 0, cStart = 0;
        int rEnd = rows - 1, cEnd = cols - 1;
        int result = 0;
        while (rStart <= rEnd && cStart <= cEnd) {
            if (grid[rStart][cStart] < 0) {
                result = result + (rEnd - rStart + 1) * (cEnd - cStart + 1);
                break;
            }
            if (grid[rEnd][cEnd] >= 0) {
                break;
            }
            int r_first_neg = rEnd;
            for (; r_first_neg >= rStart; --r_first_neg) {
                if (grid[r_first_neg][cEnd] >= 0) {
                    break;
                }
            }
            r_first_neg = r_first_neg + 1;
            int c_first_neg = cEnd;
            for (; c_first_neg >= cStart; --c_first_neg) {
                if (grid[rEnd][c_first_neg] >= 0) {
                    break;
                }
            }
            c_first_neg = c_first_neg + 1;
            result = result + (rEnd - r_first_neg + 1) + (cEnd - c_first_neg + 1) - 1;
            rStart = r_first_neg;
            cStart = c_first_neg;
            rEnd--;
            cEnd--;
        }
        return result;
    }
    int countNegatives4(vector<vector<int>>& grid) {  // 22ms
        int rows = grid.size();
        int cols = grid[0].size();
        int rStart = 0, cStart = 0;
        int rEnd = rows - 1, cEnd = cols - 1;
        int result = 0;
        while (rStart <= rEnd && cStart <= cEnd) {
            if (grid[rStart][cStart] < 0) {
                result = result + (rEnd - rStart + 1) * (cEnd - cStart + 1);
                break;
            }
            if (grid[rEnd][cEnd] >= 0) {
                break;
            }

            int up = rStart, down = rEnd;
            while (up <= down) {
                int mid = up + (down - up) / 2;
                if (grid[mid][cEnd] < 0) {
                    down = mid - 1;
                } else {
                    up = mid + 1;
                }
            }
            int r_first_neg = up;

            int left = cStart, right = cEnd;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (grid[rEnd][mid] < 0) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            int c_first_neg = left;

            result = result + (rEnd - r_first_neg + 1) + (cEnd - c_first_neg + 1) - 1;
            rStart = r_first_neg;
            cStart = c_first_neg;
            rEnd--;
            cEnd--;
        }
        return result;
    }
    int countNegatives5(vector<vector<int>>& grid) {  // 31ms
        int rows = grid.size();
        int cols = grid[0].size();
        int cStart = 0, cEnd = cols - 1;
        int rStart = 0, rEnd = rows - 1;
        int result = 0;
        while (cStart <= cEnd && rStart <= rEnd) {
            if (grid[rStart][cStart] < 0) {
                result = result + (rEnd - rStart + 1) * (cEnd - cStart + 1);
                break;
            } else if (grid[rEnd][cEnd] >= 0) {
                break;
            }

            // find the first negative in last row, mark the col
            int left = cStart, right = cEnd;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (grid[rEnd][mid] < 0) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            int c_first_neg = left;
            // find the first negative in this col
            int up = rStart, down = rEnd;
            while (up <= down) {
                int mid = up + (down - up) / 2;
                if (grid[mid][c_first_neg] < 0) {
                    down = mid - 1;
                } else {
                    up = mid + 1;
                }
            }
            int r_first_neg = up;

            result = result + (rEnd - r_first_neg + 1) * (cEnd - c_first_neg + 1);
            rEnd = r_first_neg - 1;
            cStart = c_first_neg + 1;
        }
        return result;
    }
    int countNegatives(vector<vector<int>>& grid) {  // 19ms
        int rows = grid.size();
        int cols = grid[0].size();
        int cStart = 0, cEnd = cols - 1;
        int rStart = 0, rEnd = rows - 1;
        int result = 0;
        while (cStart < cEnd ) {
            if (grid[rStart][cStart] < 0) {
                result = result + (rEnd - rStart + 1) * (cEnd - cStart + 1);
                break;
            } else if (grid[rEnd][cEnd] >= 0) {
                break;
            }

            // find the first negative in last row, mark the col
            int left = cStart, right = cEnd;
            while (left <= right) {
                int mid = (right + left) / 2;
                if (grid[rEnd][mid] < 0) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            int c_first_neg = left;
            result = result + (cEnd - c_first_neg + 1);
            cStart = c_first_neg;
            rEnd--;
        }
        if (cStart == cEnd) {
            int up = rStart, down = rEnd;
            while (up <= down) {
                int mid = (down + up) / 2;
                if (grid[mid][cEnd] < 0) {
                    down = mid - 1;
                } else {
                    up = mid + 1;
                }
            }
            int r_first_neg = up;
            result = result + (rEnd - r_first_neg + 1);
            
        }
        return result;
    }
};


int main()
{
    std::cout << "Hello World!\n";
}
