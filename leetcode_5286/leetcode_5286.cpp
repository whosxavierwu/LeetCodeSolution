// leetcode_5286.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-167/problems/shortest-path-in-a-grid-with-obstacles-elimination/
/*
Given a m * n grid, where each cell is either 0 (empty) or 1 (obstacle). 
In one step, you can move up, down, left or right from and to an empty cell.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m-1, n-1) given that you can eliminate at most k obstacles. 
If it is not possible to find such walk return -1.

Example 1:

Input:
grid =
[[0,0,0],
 [1,1,0],
 [0,0,0],
 [0,1,1],
 [0,0,0]],
k = 1
Output: 6
Explanation:
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).

Example 2:

Input:
grid =
[[0,1,1],
 [1,1,1],
 [1,0,0]],
k = 1
Output: -1
Explanation:
We need to eliminate at least two obstacles to find such a walk.

Constraints:

grid.length == m
grid[0].length == n
1 <= m, n <= 40
1 <= k <= m*n
grid[i][j] == 0 or 1
grid[0][0] == grid[m-1][n-1] == 0
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    struct node {
        int x, y, k;
        node(int _x, int _y, int _k) : x(_x), y(_y), k(_k) {}
    };
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<node> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> numOfPaths(n + 10, vector<vector<int>>(m + 10, vector<int>(k + 10, -1)));
        numOfPaths[0][0][0] = 0;
        q.push(node(0, 0, 0));
        int dx[4] = { 0, 0, 1, -1 };
        int dy[4] = { 1, -1, 0, 0 };
        while (!q.empty()) {
            node curNode = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int px = curNode.x + dx[i];
                int py = curNode.y + dy[i];
                if (px >= 0 && px < n && py >= 0 && py < m && curNode.k + grid[px][py] <= k) {
                    if (numOfPaths[px][py][curNode.k + grid[px][py]] == -1) {
                        numOfPaths[px][py][curNode.k + grid[px][py]] = numOfPaths[curNode.x][curNode.y][curNode.k] + 1;
                        q.push(node(px, py, curNode.k + grid[px][py]));
                    }
                }
            }
        }
        int result = n * m + 1;
        for (int i = 0; i <= k; ++i)
            if (numOfPaths[n - 1][m - 1][i] != -1)
                result = min(result, numOfPaths[n - 1][m - 1][i]);
        if (result == n * m + 1)
            result = -1;
        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
