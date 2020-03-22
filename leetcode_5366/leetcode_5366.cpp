// leetcode_5366.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-181/problems/check-if-there-is-a-valid-path-in-a-grid/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int di[4] = { 1, -1, 0, 0 }; 
    int dj[4] = { 0, 0, 1, -1 }; 
    int t[6] = { 4 | 8, 1 | 2, 8 | 1, 4 | 1, 8 | 2, 4 | 2 };
public:
    bool dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, 
        int i, int j, const int& n, const int& m) {
        if (i == n - 1 && j == m - 1)
            return true;
        visited[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            if (t[grid[i][j] - 1] >> k & 1 ^ 1)
                continue;
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m || visited[ni][nj])
                continue;
            int k2 = k ^ 1;
            if (t[grid[ni][nj] - 1] >> k2 & 1 ^ 1)
                continue;
            if (dfs(grid, visited, ni, nj, n, m))
                return true;
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        return dfs(grid, visited, 0, 0, n, m);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
