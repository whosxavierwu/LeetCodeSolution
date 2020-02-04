// leetcode_39.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/combination-sum/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void func(vector<int>& candidates, int& target, vector<int>& cur, vector<vector<int>>& result, int &idx) {
		for (int i = idx; i < candidates.size(); ++i) {
			int candidate = candidates[i];
			if (candidate > target)
				continue;			
			cur.push_back(candidate);
			if (candidate == target)
				result.push_back(cur);
			else {
				target -= candidate;
				func(candidates, target, cur, result, i);
				target += candidate;
			}
			cur.pop_back();
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		// v1: faster than 83.65%, less than 100.00%
		vector<vector<int>> result;
		vector<int> tmp;
		int idx = 0;
		func(candidates, target, tmp, result, idx);
		return result;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}

