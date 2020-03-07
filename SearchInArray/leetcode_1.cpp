// leetcode_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/two-sum


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> idxMap;
		for (int i = 0; i < nums.size(); ++i) {
			int residual = target - nums[i];
			if (idxMap.find(residual) != idxMap.end()) {
				return { idxMap[residual], i};
			}
			idxMap[nums[i]] = i;
		}
		return { -1, -1 };
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
