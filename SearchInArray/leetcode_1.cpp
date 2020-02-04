// leetcode_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include<vector>
using namespace std;

class Solution {
	vector<int> twoSum(vector<int>& nums, int target) {
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			int residual = target - nums[i];
			for (int j = i + 1; j < len; j++) {
				if (nums[j] == residual) {
					vector<int> result = { i, j };
					return result;
				}
			}
		}
		return vector<int>(2);
	}
};


int main()
{
	vector<int> v = {-3, 4, 3, 90};
	int target = 0; 
	Solution solution = Solution();
	vector<int> result = solution.twoSum(v, target);
	cout << result[0] << result[1] << endl;
	return 0;
}
