// leetcode_300.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/longest-increasing-subsequence/
/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	// v1: TLE
	//int lengthOfLIS(vector<int>& nums, int prevMax, int cur) {
	//	if (cur == nums.size()) return 0;
	//	int taken = (nums[cur] > prevMax) ? (1 + lengthOfLIS(nums, nums[cur], cur + 1)) : 0;
	//	int nottaken = lengthOfLIS(nums, prevMax, cur + 1);
	//	return max(taken, nottaken);
	//}
	int lengthOfLIS(vector<int>& nums) {
		// v2: 36 ms, faster than 57.84% 
		//int len = nums.size();
		//if (len == 0) return 0;
		//vector<int> dp(len, 1);
		//int maxLen = 1;
		//for (int i = 1; i < len; ++i) {
		//	for (int j = 0; j < i; ++j) {
		//		if (nums[j] < nums[i] && (dp[j] + 1) > dp[i]) {
		//			dp[i] = dp[j] + 1;
		//		}
		//	}
		//	if (dp[i] > maxLen) 
		//		maxLen = dp[i];
		//}
		//return maxLen;

		// v3: 4 ms, faster than 90.44%
		vector<int> vec;
		int len = nums.size();
		for (int i = 0; i < len; ++i) {
			auto iter = lower_bound(vec.begin(), vec.end(), nums[i]);
			if (iter == vec.end())
				vec.push_back(nums[i]);
			else
				*iter = nums[i];
		}
		return vec.size();
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
