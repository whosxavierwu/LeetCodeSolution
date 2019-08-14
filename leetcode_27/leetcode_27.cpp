// leetcode_27.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/remove-element/
/*
Given an array nums and a value val, 
remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, 
you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. 
It doesn't matter what you leave beyond the new length.

Given nums = [3,2,2,3], val = 3,
Your function should return length = 2, with the first two elements of nums being 2.
It doesn't matter what you leave beyond the returned length.

Given nums = [0,1,2,2,3,0,4,2], val = 2,
Your function should return length = 5, 
with the first five elements of nums containing 0, 1, 3, 0, and 4.
Note that the order of those five elements can be arbitrary.
It doesn't matter what values are set beyond the returned length.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		// v1: faster than 71.35% 
		//int len = nums.size();
		//int i = 0;
		//int newLen = 0;
		//while (i < len) {
		//	while (i < len && nums[i] == val) ++i;
		//	if (i >= len) break;
		//	nums[newLen] = nums[i];
		//	++newLen;
		//	++i;
		//}
		//nums.resize(newLen);
		//return newLen;

		//v2: faster than 71.35% 
		//int newLen = 0;
		//int len = nums.size();
		//for (int i = 0; i < len; ++i) {
		//	if (nums[i] != val)
		//		nums[newLen++] = nums[i];
		//}
		//nums.resize(newLen);
		//return newLen;

		// v3: faster than 6.68%
		int i = 0; 
		int len = nums.size();
		while (i < len) {
			if (nums[i] == val)
				nums[i] = nums[--len];
			else
				++i;
		}
		nums.resize(len);
		return len;
	}
};

int main()
{
	Solution sol;
	vector<int> vec = { 0,1,2,2,3,0,4,2 };
	int val = 2;
	for (int& a : vec) cout << a << " ";
	int newLen = sol.removeElement(vec, val);
	cout << endl << newLen << endl;
	for (int& a : vec) cout << a << " ";
}
