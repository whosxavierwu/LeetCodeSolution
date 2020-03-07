// leetcode_53.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/maximum-subarray/
/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums, int left, int right, int& resultGivenBegin, int& resultGivenEnd, int& sum) {
		int result = 0;
		if (left == right)
			result = resultGivenBegin = resultGivenEnd = sum = nums[left];
		else {
			int mid = left + (right - left) / 2;
			int leftResultGivenBegin, leftResultGivenEnd, leftSum;
			int rightResultGivenBegin, rightResultGivenEnd, rightSum;
			int leftResult = maxSubArray(nums, left, mid, leftResultGivenBegin, leftResultGivenEnd, leftSum);
			int rightResult = maxSubArray(nums, mid + 1, right, rightResultGivenBegin, rightResultGivenEnd, rightSum);
			result = fmax(fmax(leftResult, rightResult), leftResultGivenEnd + rightResultGivenBegin);
			// we need the fmax() here, because the max result may or may not cross the mid point
			resultGivenBegin = fmax(leftResultGivenBegin, leftSum + rightResultGivenBegin);
			resultGivenEnd = fmax(rightResultGivenEnd, rightSum + leftResultGivenEnd);
			sum = leftSum + rightSum;
		}
		return result;
	}

	int maxSubArray(vector<int>& nums) {
		// v3: divide and conquer  faster than 98.89%
		if (nums.size() == 0) return 0;
		int lmx, rmx, sum;
		int result = maxSubArray(nums, 0, nums.size() - 1, lmx, rmx, sum);
		return result;
	}

	int maxSubArray(vector<int>& nums) {
		// v1:  faster than 98.89% 
		int len = nums.size();
		vector<int> dp(len);  // dp[i] is the max sum of subarray that ends with i;
		dp[0] = nums[0];
		int max = dp[0];
		for (int i = 1; i < len; ++i) {
			dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
			if (dp[i] > max) max = dp[i];
		}
		return max;

		// v2: faster than 76.17%, why is it much slower???
		//int maxSumEndingPrev = nums[0]; // dp[i] is the max sum of subarray that ends with i;
		//int max = nums[0];
		//for (int i = 1; i < nums.size(); ++i) {
		//	int cur = nums[i] + (maxSumEndingPrev > 0 ? maxSumEndingPrev : 0);
		//	if (cur > max) max = cur;
		//	maxSumEndingPrev = cur;
		//}
		//return max;
	}
};

int main()
{
	//vector<int> in = { -2,1,-3,4,-1,2,1,-5,4 };
	vector<int> in = { 8,-19,5,-4,20 };
	Solution sol;
	cout << sol.maxSubArray(in) << endl;
	return 0;
}
