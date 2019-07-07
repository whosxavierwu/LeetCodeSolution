#include "pch.h"
#include "Solution.h"


Solution::Solution()
{
}


Solution::~Solution()
{
}


vector<int> Solution::twoSum(vector<int>& nums, int target) {
	int len = nums.size();
	for (int i = 0; i < len; i++) {
		int residual = target - nums[i];
		for (int j = i+1; j < len; j++) {
			if (nums[j] == residual) {
				vector<int> result = {i, j};
				return result; 
			}
		}
	}
	return vector<int>(2);
}
