// leetcode_cn_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode-cn.com/contest/season/2019-fall/problems/programmable-robot/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool canReach(string command, int x, int y, int rightCnt, int upCnt) {
		int rounds = min(x / rightCnt, y / upCnt);
		int curX = rightCnt * rounds;
		int curY = upCnt * rounds;
		if (curX == x && curY == y) return true;
		for (char w : command) {
			if (w == 'U') curY++;
			else curX++;
			if (curX == x && curY == y)
				break;
			if (curX > x || curY > y)
				return false;
		}
		return true;
	}
	bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
		int upCnt = 0, rightCnt = 0;
		for (char w : command)
			if (w == 'U') upCnt++;
			else rightCnt++;

		bool reach = canReach(command, x, y, rightCnt, upCnt);
		if (!reach) return false;

		for (vector<int> obstacle : obstacles) {
			if (obstacle[0] > x || obstacle[1] > y)
				continue;
			reach = canReach(command, obstacle[0], obstacle[1], rightCnt, upCnt);
			if (reach) return false;
		}
			
		return true;
	}
};

int main()
{
	Solution sol;
	string command = "URR";
	vector<vector<int>> obstacles = {  };
	int x = 4, y = 2;
	cout << sol.robot(command, obstacles, x, y) << endl;
}
