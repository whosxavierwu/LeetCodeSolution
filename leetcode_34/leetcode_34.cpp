// leetcode_34.cpp : This file contains the 'main' function. Program execution begins and ends there.
// todo https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
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
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int len = nums.size();
		int left = 0, right = len - 1;
		vector<int> result = { -1, -1 };
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (target == nums[mid]) {
				result[0] = mid;
				break;
			}
			else if (target < nums[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		return result;
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
