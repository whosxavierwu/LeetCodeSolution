// leetcode_448.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array
/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		// 1<=a[i]<=nums.size(), appear once or twice
		// O(1) space, O(n) time

		// v1: faster than 95.24%
		int len = nums.size();
		for (int i = 0; i < len; ++i) {
			// set all nums that are pointed to be negative
			int next = abs(nums[i]) - 1;
			nums[next] = -abs(nums[next]);
		}
		vector<int> result;
		for (int i = 0; i < len; ++i)
			if (nums[i] > 0)
				result.push_back(i + 1);
		return result;
	}
};

int main()
{
	Solution sol;
	vector<int> arr = { 4, 3, 2, 7, 8, 2, 3, 1 };
	vector<int> result = sol.findDisappearedNumbers(arr);
	for (int num : result)
		cout << num << endl;
}

