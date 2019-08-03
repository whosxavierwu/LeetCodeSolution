// leetcode_40.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/combination-sum-ii/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

//v1: faster than 35.28%
//class Solution {
//public:
//	void findCombinations(vector<int>& candidates, int& target, set<vector<int>>& result, vector<int>& cur, int& idx) {
//		for (int i = idx; i < candidates.size(); ++i) {
//			int candidate = candidates[i];
//			if (candidate > target)
//				continue;
//			cur.push_back(candidate);
//			if (candidate == target) {
//				result.insert(cur);
//			}
//			else {
//				target -= candidate;
//				++i;
//				findCombinations(candidates, target, result, cur, i);
//				--i;
//				target += candidate;
//			}
//			cur.pop_back();
//		}
//	}
//	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//		set<vector<int>> result;
//		vector<int> tmp;
//		int idx = 0;
//		sort(candidates.begin(), candidates.end());
//		findCombinations(candidates, target, result, tmp, idx);
//		vector<vector<int>> fin;
//		for (auto vec : result)
//			fin.push_back(vec);
//		return fin;
//	}
//};

// v2: faster than 35.28%
//class Solution {
//public:
//	void findCombinations(vector<int>& candidates, int& target, vector<vector<int>>& result, vector<int>& cur, int& idx) {
//		for (int i = idx; i < candidates.size(); ++i) {
//			int candidate = candidates[i];
//			if (candidate > target)
//				continue;
//			cur.push_back(candidate);
//			if (candidate == target) {
//				result.push_back(cur);
//			}
//			else {
//				target -= candidate;
//				++i;
//				findCombinations(candidates, target, result, cur, i);
//				--i;
//				target += candidate;
//			}
//			cur.pop_back();
//		}
//	}
//	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//		vector<vector<int>> result;
//		vector<int> tmp;
//		int idx = 0;
//		sort(candidates.begin(), candidates.end());
//		findCombinations(candidates, target, result, tmp, idx);
//		set<vector<int>> set1;
//		set1.insert(result.begin(), result.end());
//		result.clear();
//		result.insert(result.end(), set1.begin(), set1.end());
//		return result;
//	}
//};

// v3: faster than 85.52% , less than 99.23% 
class Solution {
public:
	void findCombinations(vector<vector<int>>& result, const int order, const int target, vector<int>& cur, const vector<int>& nums) {
		if (target == 0)
			result.push_back(cur);
		else {
			for (int i = order; i < nums.size(); ++i) {
				if (nums[i] > target) return;
				if (i > 0 && nums[i] == nums[i - 1] && i > order) continue;
				cur.push_back(nums[i]);
				findCombinations(result, i + 1, target - nums[i], cur, nums);
				cur.pop_back();
			}
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		vector<int> cur;
		findCombinations(result, 0, target, cur, nums);
		return result;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
