// leetcode_283.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/move-zeroes
// move zeroes to the end, inplace

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		//// v1: move non-zero numbers forward, faster than 97.42%
		//int len = nums.size();
		//int newLen = 0;
		//int zeroCount = 0;
		//for (int i = 0; i < len; ++i) {
		//	if (nums[i] != 0) {
		//		nums[newLen] = nums[i];
		//		++newLen;
		//	}
		//	else {
		//		++zeroCount;
		//	}
		//}
		//for (int i = newLen; i < len; ++i)
		//	nums[i] = 0;

		//// v2 faster than 97.42% 
		//int len = nums.size();
		//int newLen = 0;
		//for (int i = 0; i < len; ++i) {
		//	if (nums[i] != 0) {
		//		nums[newLen++] = nums[i];
		//	}
		//}
		//for (int i = newLen; i < len; ++i)
		//	nums[i] = 0;

		// v3 faster than 69.30% ??? why???
		for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++)
			if (nums[cur] != 0)
				swap(nums[lastNonZeroFoundAt++], nums[cur]);
	}
};

int main()
{
	Solution sol; 
	//vector<int> arr = { 0, 1, 0, 3, 12 };
	vector<int> arr = { 0, 0, 1, 3, 12 };
	sol.moveZeroes(arr);
	for (int num : arr)
		cout << num << endl;
	return 0;
}
