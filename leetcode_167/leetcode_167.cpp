// leetcode_167.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
//Given an array of integers that is already sorted in ascending order, 
// find two numbers such that they add up to a specific target number.

//The function twoSum should return indices of the two numbers such that they add up to the target, 
// where index1 must be less than index2.
//Your returned answers(both index1and index2) are not zero - based.
//You may assume that each input would have exactly one solutionand you may not use the same element twice.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int binarySearch(vector<int>& nums, int start, int end, int target) {
		int mid = start;
		while (start <= end) {
			mid = (start + end) / 2;
			// to avoid overflow: 
			//mid = start + (end - start) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
				start = mid + 1;
			else
				end = mid - 1;
		}
		return -1;
	}

	vector<int> twoSum(vector<int>& numbers, int target) {
		int len = numbers.size();
		vector<int> result(2, 0);
		// v1: faster than 98%
		int tmp = 0;
		for (int i = 0; i <= len / 2; ++i) {
			tmp = binarySearch(numbers, i + 1, len - 1, target - numbers[i]);
			if (tmp >= 0) {
				result[0] = i + 1;
				result[1] = tmp + 1;
				break;
			}
		}
		return result;
	}
};

int main()
{
	Solution sol;
	vector<int> nums = { 3, 24, 50, 79, 88, 150, 345 };
	int target = 200;
	vector<int> result = sol.twoSum(nums, target);
	cout << result[0] << endl << result[1] << endl;
}
