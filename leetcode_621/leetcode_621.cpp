// leetcode_621.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/task-scheduler/
/*
Given a char array representing tasks CPU need to do. 
It contains capital letters A to Z where different letters represent different tasks. 
Tasks could be done without original order. Each task could be done in one interval. 
For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, 
there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;


class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		// v1: faster than 94.85% 
		vector<int> taskCount(26);
		for (char& task : tasks) taskCount[task - 'A']++;
		sort(taskCount.begin(), taskCount.end());
		int maxVal = taskCount[25] - 1;  // why -1?
		int idleSlots = maxVal * n;
		for (int i = 24; i >= 0 && taskCount[i] > 0; --i) {
			// fill the idle slots
			idleSlots -= min(taskCount[i], maxVal);
		}
		int result = tasks.size();
		if (idleSlots > 0) result += idleSlots;
		return result;
	}
};
int main()
{
	Solution sol;
	vector<char> tasks = { 'B', 'A', 'A', 'A', 'B', 'B', 'B' };
	int n = 2;
	int result = sol.leastInterval(tasks, n);
	cout << result << endl;
}
