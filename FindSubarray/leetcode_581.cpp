// leetcode_581.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		// v2 faster than 93.17% 
		int len = nums.size();
		if (len <= 1) return 0;
		if (len == 2) return (nums[0] > nums[1]) ? 2 : 0;
		int left = 0, right = len - 1;
		while (left < len - 1 && nums[left] <= nums[left + 1])
			++left;
		while (right > 0 && nums[right - 1] <= nums[right])
			--right;
		if (left > right) return 0;
		int min = nums[left], max = nums[right];
		for (int i = left; i <= right; ++i) {
			if (nums[i] < min) min = nums[i];
			if (nums[i] > max) max = nums[i];
		}
		left = 0;
		while (left < len - 1 && nums[left] <= min)
			++left;
		right = len - 1;
		while (right > 0 && max <= nums[right])
			--right;
		return right - left + 1;

		// v1: burte force  faster than 5.08%
		//int len = nums.size();
		//int left = 0;
		//for (; left < len; ++left) {
		//	bool isMin = true;
		//	for (int i = left + 1; i < len; ++i) {
		//		if (nums[i] < nums[left]) {
		//			isMin = false;
		//			break;
		//		}
		//	}
		//	if (!isMin) {
		//		break;
		//	}
		//}
		//int right = len - 1;
		//for (; right >= 0; --right) {
		//	bool isMax = true;
		//	for (int i = right - 1; i >= 0; --i) {
		//		if (nums[i] > nums[right]) {
		//			isMax = false;
		//			break;
		//		}
		//	}
		//	if (!isMax) {
		//		break;
		//	}
		//}
		//if (left > right) return 0;
		//return right - left + 1;
	}
};

int main()
{
	vector<int> arr = { 1,3,5,4,2 };
	Solution sol;
	cout << sol.findUnsortedSubarray(arr) << endl;
	return 0;
}
