// leetcode_5271.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-164/problems/minimum-time-visiting-all-points/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minTimeToVisitAllPoints(vector<vector<int>>& points) {
		int n = points.size();
		int result = 0;
		for (int i = 0; (i + 1) < n; ++i) {
			int deltax = abs(points[i + 1][0] - points[i][0]);
			int deltay= abs(points[i + 1][1] - points[i][1]);
			result += min(deltax, deltay) + abs(deltax - deltay);
		}
		return result;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
