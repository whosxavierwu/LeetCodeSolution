// leetcode_33.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/search-in-rotated-sorted-array/
/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int binarySearch(vector<int>& nums, int left, int right, int target) {
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (target == nums[mid])
				return mid;
			else if (target < nums[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		return -1;
	}

	int doSearch(vector<int>& nums, int left, int right, int target) {
		if (nums[left] < nums[right]) 
			return binarySearch(nums, left, right, target);
		
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
			return mid;
		if (nums[left] == target)
			return left;
		if (nums[right] == target)
			return right;
		if (left >= right)
			return -1;

		if (nums[mid] > nums[left]) {
			if (nums[left] < target && target < nums[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		else if (nums[mid] < nums[right]) {
			if (nums[mid] < target && target < nums[right])
				left = mid + 1;
			else
				right = mid - 1;
		}
		else
			return -1;
		return doSearch(nums, left, right, target);
	}

	int searchRotatedSortedArray(vector<int>& nums, int left, int right, int target) {
		while (left <= right && nums[left] >= nums[right]) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) return mid;
			if (nums[left] == target) return left;
			if (nums[right] == target) return right;
			if (nums[mid] > nums[left]) {
				if (nums[left] < target && target < nums[mid])
					right = mid - 1;
				else
					left = mid + 1;
			}
			else if (nums[mid] < nums[right]) {
				if (nums[mid] < target && target < nums[right])
					left = mid + 1;
				else
					right = mid - 1;
			}
			else
				return -1;
		}
		return binarySearch(nums, left, right, target);
	}

	int doSearch4(vector<int>& nums, int left, int right, int target) {
		while (left <= right && nums[left] >= nums[right]) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) return mid;
			if (nums[left] == target) return left;
			if (nums[right] == target) return right;
			
			if (nums[left] < target && target < nums[mid])
				right = mid - 1;
			else if (nums[mid] < target && target < nums[right])
				left = mid + 1;
			else if (nums[left] < nums[mid])
				left = mid + 1;
			else if (nums[mid] < nums[right])
				right = mid - 1;
			else
				return -1;
		}
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (target == nums[mid])
				return mid;
			else if (target < nums[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		return -1;
	}
	int search(vector<int>& nums, int target) {
		if (nums.empty()) return -1;
		// v1: 8 ms, faster than 10.67% 
		// v2: 4 ms, faster than 80.09%
		//return doSearch(nums, 0, nums.size() - 1, target);
		// v3:  4 ms, faster than 80.09%
		return searchRotatedSortedArray(nums, 0, nums.size() - 1, target);
		// v4: 4 ms, faster than 80.09%
		//return doSearch4(nums, 0, nums.size() - 1, target);
	}
};
int main()
{
	Solution sol;
	vector<int> nums = { 4,5,6,7,0,1,2 };
	cout << sol.search(nums, 0) << endl;
	cout << sol.search(nums, 3) << endl;
}
