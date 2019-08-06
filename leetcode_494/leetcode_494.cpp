// leetcode_494.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/target-sum/
/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. 
Now you have 2 symbols + and -. 
For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

#include <iostream>
#include <vector>
using namespace std;

// v1: faster than 38.76% 
//class Solution {
//public:
//	int findTargetSumWays(vector<int>& nums, int S, int right, vector<int>& min, vector<int>&max) {
//		if (S > max[right] || S < min[right])
//			return 0;
//		if (right == 0)
//			return (nums[0] == S) + (-nums[0] == S);
//		int result = findTargetSumWays(nums, S - nums[right], right - 1, min, max);
//		result += findTargetSumWays(nums, S + nums[right], right - 1, min, max);
//		return result;
//	}
//	int findTargetSumWays(vector<int>& nums, int S) {
//		vector<int> max;
//		vector<int> min;
//		for (int num : nums) {
//			max.push_back((max.empty() ? 0 : max.back()) + num);
//			min.push_back((min.empty() ? 0 : min.back()) - num);
//		}
//		return findTargetSumWays(nums, S, nums.size() - 1, min, max);
//	}
//};

// v2 TLE
//class Solution {
//public:
//	int findTargetSumWays(vector<int>& nums, int S) {
//		vector<int> max, min;
//		for (int num : nums) {
//			max.push_back((max.empty() ? 0 : max.back()) + num);
//			min.push_back((min.empty() ? 0 : min.back()) - num);
//		}
//		vector<int> vec;
//		vec.push_back(nums[0]);
//		vec.push_back(-nums[0]);
//		for (int i = 1; i < nums.size(); ++i) {
//			vector<int> tmp;
//			for (int num : vec) {
//				if (num + nums[i] <= max[i])
//					tmp.push_back(num + nums[i]);
//				if (num - nums[i] >= min[i])
//					tmp.push_back(num - nums[i]);
//			}
//			vec = tmp;
//		}
//		int result = 0;
//		for (int num : vec)
//			if (num == S)
//				++result;
//		return result;
//	}
//};

// v3 faster than 35.23%
//class Solution {
//public:
//	void findTargetSumWays(vector<int>& nums, int& S, int& right, vector<int>& min, vector<int>&max, int& result) {
//		if (S > max[right] || S < min[right])
//			return ;
//		if (right == 0) {
//			result += (nums[0] == S) + (-nums[0] == S);
//			return;
//		}
//		S -= nums[right];
//		right -= 1;
//		findTargetSumWays(nums, S, right, min, max, result);
//		right += 1;
//		S += nums[right];
//
//		S += nums[right];
//		right -= 1;
//		findTargetSumWays(nums, S, right, min, max, result);
//		right += 1;
//		S -= nums[right];
//	}
//	int findTargetSumWays(vector<int>& nums, int S) {
//		vector<int> max, min;
//		for (int num : nums) {
//			max.push_back((max.empty() ? 0 : max.back()) + num);
//			min.push_back((min.empty() ? 0 : min.back()) - num);
//		}
//		int result = 0;
//		int right = nums.size() - 1;
//		findTargetSumWays(nums, S, right, min, max, result);
//		return result;
//	}
//};

// v4 faster than 33.34%
//class Solution {
//public:
//	pair<int, int> findTargetSumWays(vector<int>& nums, int S, int right, vector<int>& min, vector<int>& max) {
//		if (S > max[right] || S < min[right]) return make_pair(0, 0);
//		if (right == 0) {
//			return make_pair(nums[0] == S, -nums[0] == S);
//		}
//		pair<int, int> result;
//		// plus cur num
//		pair<int, int> prev1 = findTargetSumWays(nums, S - nums[right], right - 1, min, max);
//		result.first = prev1.first + prev1.second;
//		// minus cur num
//		pair<int, int> prev2 = findTargetSumWays(nums, S + nums[right], right - 1, min, max);
//		result.second = prev2.first + prev2.second;
//		return result;
//	}
//
//	int findTargetSumWays(vector<int>& nums, int S) {
//		vector<int> max, min;
//		for (int num : nums) {
//			max.push_back((max.empty() ? 0 : max.back()) + num);
//			min.push_back((min.empty() ? 0 : min.back()) - num);
//		}
//		pair<int, int> result = findTargetSumWays(nums, S, nums.size() - 1, min, max);
//		return result.first + result.second;
//	}
//};

// v5: faster than 100.00% 
class Solution {
public: 
	int subsetSum(vector<int>& nums, int sum) {
		vector<int> dp(sum + 1, 0);
		dp[0] = 1;
		for (int n : nums) {
			for (int i = sum; i >= n; --i) {
				dp[i] += dp[i - n]; //why???
			}
		}
		return dp[sum];
	}
	int findTargetSumWays(vector<int>& nums, int S) {
		// https://leetcode.com/problems/target-sum/discuss/97334/Java-(15-ms)-C%2B%2B-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation
		/*
		                  sum(P) - sum(N) = target
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
                       2 * sum(P) = target + sum(nums)
					   now turn to find out P that sum(P)=(target+sum(nums))/2
		*/
		int sum = 0; 
		for (int num : nums) sum += num;
		// (S + sum) & 1 means is odd, in this case, there is no valid paths, since sum(P) is even
		return sum < S || ((S + sum) & 1) ? 0 : subsetSum(nums, (S + sum) >> 1);
	}
};

int main()
{
	Solution sol;
	//vector<int> nums = { 1,1,1,1,1 };
	//int S = 3;
	vector<int> nums = { 1,0 };
	int S = 1;
	int result = sol.findTargetSumWays(nums, S);
	cout << result << endl;
	return 0;
}
