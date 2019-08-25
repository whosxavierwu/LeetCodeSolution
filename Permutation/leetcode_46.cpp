// leetcode_46.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/permutations/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> func(vector<int> nums, int start, int end) {
		if (start == end) {
			return { {nums[start]} };
		}
		else if (start + 1 == end) {
			return { {nums[start], nums[end]}, {nums[end], nums[start]} };
		}
		vector<vector<int>> result;
		vector<vector<int>> prevResult = func(nums, start, end - 1);
		for (int i = start; i <= end; ++i) {
			for (vector<int> prevList : prevResult) {		
				prevList.insert(prevList.begin() + i, nums[end]);
				result.push_back(prevList);
			}
		}
		return result;
	}

	vector<vector<int>> permute(vector<int>& nums) {
		// v1: recursive faster than 73.28%
		// return func(nums, 0, nums.size() - 1);
		
		// v2: iterative faster than 98.65%
		//vector<vector<int>> result;
		//result.push_back({ nums[0] });
		//for (int curIdx = 1; curIdx < nums.size(); ++curIdx) {
		//	vector<vector<int>> newResult;
		//	for (int insertPos = 0; insertPos <= curIdx; ++insertPos) {
		//		for (vector<int> tmpComb : result) {
		//			tmpComb.insert(tmpComb.begin() + insertPos, nums[curIdx]);
		//			newResult.push_back(tmpComb);
		//		}
		//	}
		//	result = newResult;
		//}
		//return result;

		
	}
};

int main()
{
	vector<int> input = { 1, 2, 3 };
	Solution sol;
	vector<vector<int>> result = sol.permute(input);
	for (vector<int> vec : result) {
		for (int a : vec)
			cout << a << " ";
		cout << endl;
	}
	return 0;
	
}
