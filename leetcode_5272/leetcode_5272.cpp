// leeetcode_5272.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-164/problems/count-servers-that-communicate/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int countServers(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int totalServers = 0;
		vector<int> rowSum(m, 0);
		vector<int> colSum(n, 0);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 1) {
					rowSum[i]++;
					colSum[j]++;
					totalServers++;
				}
			}
		}
		int aloneServers = 0; 
		for (int i = 0; i < m; ++i) {
			if (rowSum[i] != 1)
				continue;
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 1 && colSum[j] == 1)
					aloneServers++;
			}
		}
		return totalServers - aloneServers;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
