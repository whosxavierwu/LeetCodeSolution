// leetcode_5285.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-167/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/
/*
Given a m x n matrix mat and an integer threshold. Return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.



Example 1:


Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
Output: 2
Explanation: The maximum side length of square with sum less than 4 is 2 as shown.
Example 2:

Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
Output: 0
Example 3:

Input: mat = [[1,1,1,1],[1,0,0,0],[1,0,0,0],[1,0,0,0]], threshold = 6
Output: 3
Example 4:

Input: mat = [[18,70],[61,1],[25,85],[14,40],[11,96],[97,96],[63,45]], threshold = 40184
Output: 2


Constraints:

1 <= m, n <= 300
m == mat.length
n == mat[i].length
0 <= mat[i][j] <= 10000
0 <= threshold <= 10^5
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> prevSum(n);
        int result = 0;
        for (int r = 0; r < m; ++r) {
            if (result == 0) {
                for (int c = 0; c < n; ++c) {
                    if (mat[r][c] <= threshold) {
                        result = 1;
                        for (int c1 = 0; c1 < n; ++c1)
                            prevSum[c1] = mat[r][c1];
                        break;
                    }
                }
            }
            else {
                bool found = false;
                for (int c = 0; (c+result) < n; ++c) {
                    int tmp = 0;
                    for (int k = 0; k <= result; ++k) {
                        tmp += prevSum[c + k] + mat[r][c + k];
                    }
                    if (tmp <= threshold) {
                        result += 1;
                        for (int c = 0; c < n; ++c) {
                            prevSum[c] = 0;
                            for (int k = 0; k < result; ++k) {
                                prevSum[c] += mat[r - k][c];
                            }
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    for (int c = 0; c < n; ++c) {
                        prevSum[c] = 0;
                        for (int k = 0; k < result; ++k) {
                            prevSum[c] += mat[r - k][c];
                        }
                    }
                }
            }
        }
        return result;
    }
};


int main()
{
    std::cout << "Hello World!\n";
}

