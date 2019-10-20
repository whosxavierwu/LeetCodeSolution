// leetcode_5230.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-159/problems/check-if-it-is-a-straight-line/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool checkStraightLine(vector<vector<int>>& coordinates) {
		int len = coordinates.size();
		if (coordinates[1][0] == coordinates[0][0]) {
			for (int i = 2; i < len; ++i) {
				if (coordinates[i][0] != coordinates[0][0])
					return false;
			}
		}
		else {
			float rate = float(coordinates[1][1] - coordinates[0][1]) / float(coordinates[1][0] - coordinates[0][0]);
			for (int i = 2; i < len; ++i) {
				float tmp = float(coordinates[i][1] - coordinates[0][1]) / float(coordinates[i][0] - coordinates[0][0]);
				if (tmp != rate)
					return false;
			}
		}
		return true;
	}
};
int main()
{
	return 0;
}
