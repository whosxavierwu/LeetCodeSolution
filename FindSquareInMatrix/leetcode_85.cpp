// leetcode_85.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/maximal-rectangle/
/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        //// v1: 24 ms, faster than 74.43%
        //if (matrix.empty()) return 0;
        //int N = matrix.size(); 
        //int M = matrix[0].size();
        //vector<int> left(M, 0);
        //vector<int> right(M, M);
        //vector<int> height(M, 0);
        //int result = 0;
        //for (int i = 0; i < N; ++i) {
        //    int cur_left = 0, cur_right = M;
        //    // height 
        //    for (int j = 0; j < M; ++j)
        //        height[j] = (matrix[i][j] == '1') ? (height[j] + 1) : 0;
        //    // left 
        //    for (int j = 0; j < M; ++j)
        //        if (matrix[i][j] == '1')
        //            left[j] = max(left[j], cur_left);
        //        else {
        //            left[j] = 0;
        //            cur_left = j + 1;  // left to right, find the last non-zero
        //        }
        //    // right 
        //    for (int j = M - 1; j >= 0; --j)
        //        if (matrix[i][j] == '1')
        //            right[j] = min(right[j], cur_right);
        //        else {
        //            right[j] = M;
        //            cur_right = j;  // right to left, find the last 0
        //        }
        //    for (int j = 0; j < M; ++j)
        //        result = max(result, (right[j] - left[j]) * height[j]);
        //}
        //return result;

        // v2 20 ms, faster than 92.78%
        if (matrix.empty()) return 0;
        int N = matrix.size();
        int M = matrix[0].size();
        vector<int> left(M, 0);
        vector<int> right(M, M);
        vector<int> height(M, 0);
        int result = 0;
        for (int i = 0; i < N; ++i) {
            int cur_left = 0, cur_right = M;
            for (int j = 0; j < M; ++j) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                    left[j] = max(left[j], cur_left);
                }
                else {
                    height[j] = 0;
                    left[j] = 0;
                    cur_left = j + 1;
                }
                if (matrix[i][M - 1 - j] == '1') {
                    right[M - 1 - j] = min(right[M - 1 - j], cur_right);
                }
                else {
                    right[M - 1 - j] = M;
                    cur_right = M - 1 - j;
                }
            }
            for (int j = 0; j < M; ++j)
                result = max(result, (right[j] - left[j]) * height[j]);
        }
        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
