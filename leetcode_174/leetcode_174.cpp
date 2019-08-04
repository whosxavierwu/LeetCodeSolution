// leetcode_174.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/dungeon-game/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	int calculateHP(vector<vector<int>>& dungeon, const pair<int, int>& cur, int& curHP) {
		curHP += dungeon[cur.first][cur.second];
		int minHP1 = calculateHP(dungeon, make_pair(cur.first + 1, cur.second), curHP);
		int minHP2 = calculateHP(dungeon, make_pair(cur.first, cur.second + 1), curHP);
		curHP -= dungeon[cur.first][cur.second];
		return fmin(minHP1, minHP2);
	}
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int N = dungeon.size();
		int M = dungeon[0].size();
		
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> matrix = {
		{1,-3,3},
		{0,-2,0},
		{-3,-3,-3} 
	};
	int result = sol.calculateMinimumHP(matrix);
	cout << result << endl;
	return 0;
}
