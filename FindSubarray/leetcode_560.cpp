// leetcode_560.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/subarray-sum-equals-k/
/*
Given an array of integers and an integer k, 
you need to find the total number of continuous subarrays whose sum equals to k.

Input:nums = [1,1,1], k = 2
Output: 2
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		// v2:faster than 89.75% 
		unordered_map<int, int> mmap;
		int count = 0, sum = 0, len = nums.size();
		mmap[0] = 1;
		for (int i = 0; i < len; ++i) {
			sum += nums[i];
			if (mmap.find(sum - k) != mmap.end())
				count += mmap[sum - k];
			mmap[sum] += 1;
		}
		return count;

		// v1: faster than 18.47% 
		//int len = nums.size();
		//int result = 0;
		//for (int i = 0; i < len; ++i) {
		//	for (int j = i, sum = 0; j < len; ++j) {
		//		sum += nums[j];
		//		if (sum == k)
		//			++result;
		//	}
		//}
		//return result;
	}
};

int main()
{
	Solution sol; 
	vector<int> nums = { 1, 1, 1 };
	cout << sol.subarraySum(nums, 2) << endl;
}

