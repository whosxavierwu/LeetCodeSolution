// leetcode_78.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/subsets/
/*
Given a set of distinct integers, nums, return all possible subsets (the power set). 
including the null set
Note: The solution set must not contain duplicate subsets.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void findSubsets(vector<int>& nums, int end, vector<vector<int>>& result) {
		if (end == 0) {
			result.push_back({});
			result.push_back({ nums[0] });
			return;
		}
		findSubsets(nums, end - 1, result);
		vector<vector<int>> tmp;
		for (vector<int> tmpSets : result) {
			tmpSets.push_back(nums[end]);
			tmp.push_back(tmpSets);
		}
		result.insert(result.end(), tmp.begin(), tmp.end());
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		// v3 faster than 62.42%
		int n = nums.size(), p = 1 << n;
		vector<vector<int>> subs(p);
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < n; j++) {
				if ((i >> j) & 1) {
					subs[i].push_back(nums[j]);
				}
			}
		}
		return subs;

		// v2 faster than 62.42% 
		//if (nums.empty()) return { {} };
		//vector<vector<int>> result = { {} };
		//for (int num : nums) {
		//	int len = result.size();
		//	for (int i = 0; i < len; ++i) {
		//		result.push_back(result[i]);
		//		result.back().push_back(num);
		//	}
		//}
		//return result;

		// v1 faster than 62.42%
		//if (nums.empty()) return { {} };
		//vector<vector<int>> result;
		//findSubsets(nums, nums.size() - 1, result);
		//return result;
	}
};

int main()
{
	vector<int> nums = { 1, 2, 3 };
	Solution sol;
	vector<vector<int>> subset = sol.subsets(nums);
	for (vector<int> vec : subset) {
		for (int a : vec)
			cout << a << " ";
		cout << endl;
	}
	return 0;
}
