// leetcode_56.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/merge-intervals/
/*
Given a collection of intervals, merge all overlapping intervals.

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		// 16 ms, faster than 93.93% 
		sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {return a[0] < b[0]; });
		vector<vector<int>> result;
		for (vector<int>& interval : intervals) {
			if (result.empty() || result.back()[1] < interval[0]) {
				result.push_back(interval);
			}
			else {
				int len = result.size();
				result[len - 1][1] = max(result[len - 1][1], interval[1]);
			}
		}
		return result;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}
