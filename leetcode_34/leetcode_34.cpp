// leetcode_34.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
/*
Given an array of integers nums sorted in ascending order, 
find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int searchLowBound(const vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return left;
	}
	vector<int> searchRange(vector<int>& nums, int target) {
		// v1: 12 ms, faster than 35.50% 
		//if (nums.empty()) return { -1, -1 };
		//int left = 0, right = nums.size() - 1;
		//vector<int> result(2, -1);
		//while (left < right) {
		//	int mid = left + (right - left) / 2;
		//	if (nums[mid] < target)
		//		left = mid + 1;
		//	else
		//		right = mid;
		//}
		//if (nums[left] != target)
		//	return result;
		//result[0] = left;
		//right = nums.size() - 1;
		//while (left < right) {
		//	int mid = left + (right - left) / 2 + 1;
		//	if (nums[mid] > target)
		//		right = mid - 1;
		//	else
		//		left = mid;
		//}
		//result[1] = right;
		//return result;

		// v2:  8 ms, faster than 85.29% 
		int idx1 = searchLowBound(nums, target);
		int idx2 = searchLowBound(nums, target + 1) - 1;
		if (idx1 <= idx2)
			return { idx1, idx2 };
		else
			return { -1, -1 };
	}
};

int main()
{
	Solution sol;
	vector<int> nums = { 5,7,7,8,8,10 };
	int target = 8;
	vector<int> result = sol.searchRange(nums, target);
	for (int a : result) cout << a << " ";
	cout << endl;
}
