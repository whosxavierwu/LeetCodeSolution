// leetcode_561.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/array-partition-i/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		int len = size(nums);
		sort(nums.begin(), nums.end());
		int sum = 0;
		for (int i = 0; i < len; i += 2) {
			sum += nums[i];
		}
		return sum;
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 1, 4, 2, 3 };
	int result = s.arrayPairSum(nums);
	cout << result << endl;
}

