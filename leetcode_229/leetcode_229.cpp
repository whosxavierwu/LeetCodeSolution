// leetcode_229.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		float vote = 0.0;
		int key = 0;
		int tmp = 0;
		vector<int> result(0);
		int len = nums.size();
		
		key = nums[0];
		for (int i = 0; i < len; ++i) {
			if (key == nums[i])
				vote += 1.5;
			else
				vote -= 1.0;
			if (vote <= 0.0) {
				key = nums[i];
				vote = 1.5;
			}
		}
		if (vote > 0)
			result.push_back(key);

		if (!result.empty()) {
			tmp = result[0];
			vote = 0.0;
			for (int i = 0; i < len; ++i)
				if (nums[i] != tmp) {
					key = nums[i];
					break;
				}
			for (int i = 0; i < len; ++i) {
				if (key == nums[i])
					vote += 1.5;
				else
					vote -= 1.0;
				if (vote <= 0.0) {
					key = nums[i];
					vote = 1.5;
				}
			}
			if (vote > 0)
				result.push_back(key);
		}
		return result;
	}
};

int main()
{
	Solution sol;
	//vector<int> nums = {6,5,5};
	//vector<int> nums = {3,2,3};
	vector<int> nums = {1,2};
	vector<int> res = sol.majorityElement(nums);
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;
	return 0;
}
