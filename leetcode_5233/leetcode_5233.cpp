// leetcode_5233.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-159/problems/maximum-profit-in-job-scheduling/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct job {
	int start, end, profit;
	bool operator<(const job& other) const {
		return end < other.end;
	}
};

class Solution {
public:
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		// generate time axis
		vector<int> times;
		times.push_back(-1e9);  // why?
		for (int time : endTime) times.push_back(time);
		sort(times.begin(), times.end());
		// a common way to drop duplicates
		times.resize(unique(times.begin(), times.end()) - times.begin());

		int T = times.size();
		int N = startTime.size();
		vector<job> jobs;

		// sort jobs by endtime
		for (int i = 0; i < N; i++)
			jobs.push_back({ startTime[i], endTime[i], profit[i] });
		sort(jobs.begin(), jobs.end());

		vector<long long> dp(T, 0);

		for (job jb : jobs) {
			int start = jb.start;
			int end = jb.end;
			// upper_bound >; lower_boud >=;
			start = upper_bound(times.begin(), times.end(), start) - times.begin() - 1;
			end = lower_bound(times.begin(), times.end(), end) - times.begin();

			dp[end] = max(dp[end], dp[start] + jb.profit);

			if (end >= 0)  // why?
				dp[end] = max(dp[end], dp[end - 1]);
		}

		return *max_element(dp.begin(), dp.end());
	}
};

// v1: TLE
//class Solution {
//public:
//	int doSchedule(vector<int>& startTime, vector<int>& endTime, vector<int>& profit, int st, int et) {
//		int maxProfit = 0;
//		for (int i = 0; i < profit.size(); ++i) {
//			if (startTime[i] == st && endTime[i] == et) {
//				maxProfit = max(maxProfit, profit[i]);
//			}
//		}
//		for (int i = st + 1; i < et; ++i) {
//			int tmp1 = doSchedule(startTime, endTime, profit, st, i);
//			int tmp2 = doSchedule(startTime, endTime, profit, i, et);
//			maxProfit = max(maxProfit, tmp1 + tmp2);
//		}
//		return maxProfit;
//	}
//	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//		int minTime = INT_MAX;
//		int maxTime = INT_MIN;
//		int N = profit.size();
//		for (int i = 0; i < N; ++i) {
//			if (startTime[i] < minTime) minTime = startTime[i];
//			if (endTime[i] > maxTime) maxTime = endTime[i];
//		}
//		return doSchedule(startTime, endTime, profit, minTime, maxTime);
//	}
//};

int main()
{
	Solution sol;

	//vector<int> startTime = { 1,2,3,3 };
	//vector<int> endTime = { 3,4,5,6 };
	//vector<int> profit = { 50,10,40,70 };

	//vector<int> startTime = { 1,2,3,4,6 };
	//vector<int> endTime = { 3,5,10,6,9 };
	//vector<int> profit = { 20,20,100,70,60 };

	//vector<int> startTime = { 1,1,1 };
	//vector<int> endTime = { 2,3,4 };
	//vector<int> profit = { 5,6,4 };

	vector<int> startTime = { 4, 2, 4, 8, 2 };
	vector<int> endTime = { 5, 5, 5, 10, 8 };
	vector<int> profit = { 1, 2, 8, 10, 4 };

	cout << sol.jobScheduling(startTime, endTime, profit) << endl;
}
