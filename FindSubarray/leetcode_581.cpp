// leetcode_581.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
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
	}
};

int main()
{
	vector<int> arr = { 1,3,5,4,2 };
	Solution sol;
	cout << sol.findUnsortedSubarray(arr) << endl;
	return 0;
}
