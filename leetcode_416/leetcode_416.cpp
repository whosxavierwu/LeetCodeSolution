// leetcode_416.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/partition-equal-subset-sum/
/*
Given a non-empty array containing only positive integers, 
find if the array can be partitioned into two subsets 
such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.
*/
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;


class Solution {
public:
	bool canPartition(vector<int>& nums) {
		// v1:  12 ms, faster than 87.07%, 8.2 MB, less than 100.00% 
		const int max_value = 100;
		const int max_len = 200;
		bitset<max_value* max_len / 2 + 1> bits(1);  // bits[i] marks if there is a sum=i
		int sum = 0;
		for (int& num : nums) {
			sum += num;
			bits |= bits << num;
		}
		return (sum % 2 == 0) && bits[sum / 2];

		// v2  156 ms, faster than 32.39% 
		//int sum = 0;
		//for (int num : nums) sum += num;
		//if (sum % 2) return false;
		//int target = sum / 2;
		//vector<bool> dp(target + 1);
		//dp[0] = true;
		//for (int num : nums) 
		//	for (int i = target; i >= num; --i) 
		//		dp[i] = dp[i] || dp[i - num];
		//return dp[target];
	}
};

int main()
{
    std::cout << "Hello World!\n";
}


