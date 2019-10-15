// leetcode_56.cpp : This file contains the 'main' function. Program execution begins and ends there.
// todo https://leetcode.com/problems/merge-intervals/
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
using namespace std;

class Solution {
public:
	int findBigBoss(int x, vector<int>& bossOf) {
		return bossOf[x] == x ? x : findBigBoss(bossOf[x], bossOf);
	}
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int numOfIntervals = intervals.size();
		if (numOfIntervals <= 1) return intervals;

		vector<int> bossOf;
		for (int i = 0; i < numOfIntervals; ++i)
			bossOf.push_back(i);
		
		for (int i = 0; i < numOfIntervals; ++i) {
			for (int j = i + 1; j < numOfIntervals; ++j) {
				if (overlap(i, j)) {
					int boss1 = findBigBoss(i, bossOf);
					int boss2 = findBigBoss(j, bossOf);
					if (boss1 != boss2) {
						// merge two groups 
						bossOf[boss2] = boss1;
					}
				}
			}
		}
			
	}
};
int main()
{
    std::cout << "Hello World!\n";
}
