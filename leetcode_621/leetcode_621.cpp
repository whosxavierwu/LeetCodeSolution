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

bool cmp(pair<char, int>& p1, pair<char, int>& p2) {
	return p1.second > p2.second;
}

class Solution {
public:
	 
	int leastInterval(vector<char>& tasks, int n) {
		unordered_map<char, int> cntMap;
		for (char& c : tasks) cntMap[c] += 1;
		priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> pq;
		for (auto iter = cntMap.begin(); iter != cntMap.end(); ++iter)
			pq.push(make_pair(iter->second, iter->first));
		while (!pq.empty()) {
			break;
		}
		return 0;
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
