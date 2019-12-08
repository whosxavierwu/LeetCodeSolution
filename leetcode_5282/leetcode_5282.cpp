// leetcode_5282.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-166/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/
/*
Given a m x n binary matrix mat. 
In one step, you can choose one cell and flip it and all the four neighbours of it if they exist (Flip is changing 1 to 0 and 0 to 1). 
A pair of cells are called neighboors if they share one edge.

Return the minimum number of steps required to convert mat to a zero matrix or -1 if you cannot.

Binary matrix is a matrix with all cells equal to 0 or 1 only.

Zero matrix is a matrix with all cells equal to 0.

Example 1:
Input: mat = [[0,0],[0,1]]
Output: 3
Explanation: One possible solution is to flip (1, 0) then (0, 1) and finally (1, 1) as shown.
Example 2:

Input: mat = [[0]]
Output: 0
Explanation: Given matrix is a zero matrix. We don't need to change it.
Example 3:

Input: mat = [[1,1,1],[1,0,1],[0,0,0]]
Output: 6
Example 4:

Input: mat = [[1,0,0],[1,0,0]]
Output: -1
Explanation: Given matrix can't be a zero matrix


Constraints:

m == mat.length
n == mat[0].length
1 <= m <= 3
1 <= n <= 3
mat[i][j] is 0 or 1.

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int result = -1;
        for (int i = 0; i < (1 << (n * m)); ++i) {  // all possible actions
            vector<vector<int>> newMat = mat;
            int cnt = 0;
            for (int j = 0; j < n * m; ++j) {  // all points in newMat
                if (i & (1 << j)) {
                    ++cnt;
                    int a = j / m;
                    int b = j % m;
                    // flip it and its neighbors
                    newMat[a][b] ^= 1;
                    if (a > 0) newMat[a - 1][b] ^= 1;
                    if (b > 0) newMat[a][b - 1] ^= 1;
                    if (a < n - 1) newMat[a + 1][b] ^= 1;
                    if (b < m - 1) newMat[a][b + 1] ^= 1;
                }
            }
            bool ok = true;
            for (vector<int>& j : newMat)
                for (int k : j)
                    if (k > 0)
                        ok = false;
            if (ok && (result == -1 || cnt < result))
                result = cnt;
        }
        return result;
    }
};


int main()
{
    std::cout << "Hello World!\n";
}

