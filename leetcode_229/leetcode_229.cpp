// leetcode_229.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		// v1: Boyer-Moore Majority Vote; faster than 94%
		int len = nums.size();
		int vote1 = 0, vote2 = 0;
		int candidate1 = 0, candidate2 = 1;  // two candidate must be different
		for (int i = 0; i < len; ++i) {
			if (nums[i] == candidate1)  // assentor of cand1
				vote1++;
			else if (nums[i] == candidate2)  // assentor of cand2
				vote2++;
			// NOTE: cand2 isn't consider as a dissenter to cand1!!! 
			else if (vote1 == 0) {  //  dissenter to replace cand1
				candidate1 = nums[i];
				vote1 = 1;
			}
			else if (vote2 == 0) {  // dissenter to replace cand2
				candidate2 = nums[i];
				vote2 = 1;
			}
			else {  // dissenter but not enough to replace cand1 or cand2
				vote1--;
				vote2--;
			}
		} // what do vote mean now ???
		// lets check if two candidate are corrected
		// but why we need round 2??? can we simply use vote1 & vote2 after round1?
		vote1 = 0;
		vote2 = 0;
		for (int i = 0; i < len; ++i) {
			if (nums[i] == candidate1)
				vote1++;
			else if (nums[i] == candidate2)
				vote2++;
		}
		vector<int> result(0);
		if (vote1 > len / 3)
			result.push_back(candidate1);
		if (vote2 > len / 3)
			result.push_back(candidate2);
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
