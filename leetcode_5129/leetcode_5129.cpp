// leetcode_5129.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/biweekly-contest-15/problems/minimum-falling-path-sum-ii/
/*
Given a square grid of integers arr, a falling path with non-zero shifts is a choice of exactly one element from each row of arr, such that no two elements chosen in adjacent rows are in the same column.

Return the minimum sum of a falling path with non-zero shifts.



Example 1:

Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation:
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.


Constraints:

1 <= arr.length == arr[i].length <= 200
-99 <= arr[i][j] <= 99
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> dp0(n, INT_MAX);
        for (int r = 0; r < n; ++r) {
            if (r == 0) {
                for (int c = 0; c < n; ++c)
                    dp0[c] = arr[r][c];
            }
            else {
                vector<int> dp1(n, INT_MAX);
                for (int c0 = 0; c0 < n; ++c0) {
                    for (int c1 = 0; c1 < n; ++c1) {
                        if (c0 != c1)
                            dp1[c1] = min(dp1[c1], dp0[c0] + arr[r][c1]);
                    }
                }
                dp0 = dp1;
            }
        }
        int result = INT_MAX;
        for (int c = 0; c < n; ++c)
            result = min(result, dp0[c]);
        return result;
    }
};


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {

        int n = arr.size();
        vector<int> dp0(n, INT_MAX);
        for (int r = 0; r < n; ++r)
        {
            if (r == 0)
            {
                for (int c = 0; c < n; ++c) dp0[c] = arr[r][c];
            }
            else
            {
                vector<int> dp1(n, INT_MAX);
                for (int c0 = 0; c0 < n; ++c0)
                    for (int c1 = 0; c1 < n; ++c1)
                    {
                        if (c0 != c1) dp1[c1] = min(dp1[c1], dp0[c0] + arr[r][c1]);
                    }
                dp0 = dp1;
            }

        }

        int res = INT_MAX;
        for (int c = 0; c < n; ++c)
            res = min(res, dp0[c]);

        return res;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
