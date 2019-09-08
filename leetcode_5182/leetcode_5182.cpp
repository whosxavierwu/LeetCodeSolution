// leetcode_5182.cpp : This file contains the 'main' function. Program execution begins and ends there.
// todo https://leetcode.com/contest/weekly-contest-153/problems/maximum-subarray-sum-with-one-deletion/
/*
Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.

Note that the subarray needs to be non-empty after deleting one element.

Constraints:

1 <= arr.length <= 10^5
-10^4 <= arr[i] <= 10^4
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maximumSum(vector<int>& arr) {
		// v1: TLE
		//int len = arr.size();
		//if (len == 1) return arr[0];
		//int result = arr[0];
		//for (int i = 1; i < len; ++i) {
		//	int runSum = arr[i];
		//	int maxSum = arr[i];
		//	int minVal = INT_MAX;
		//	for (int j = i - 1; j >= 0; --j) {
		//		runSum += arr[j];
		//		minVal = min(minVal, arr[j]);
		//		maxSum = max(maxSum, minVal < 0 ? (runSum - minVal) : runSum);
		//	}
		//	result = max(maxSum, result);
		//}
		//return result;

		int len = arr.size();
		vector<int> dp(len);
		dp[0] = arr[0];
		int result = dp[0];
		for (int i = 1; i < len; ++i) {
			if (dp[i - 1] < 0) {
				
			}
			result = max(result, dp[i]);
		}
		return result;
	}
};
int main()
{
	Solution sol;
	vector<int> arr;
	arr = { 1,-2,0,3 };
	cout << sol.maximumSum(arr) << endl;
	arr = { 1,-2,-2,3 };
	cout << sol.maximumSum(arr) << endl;
	arr = { -1,-1,-1,-1 };
	cout << sol.maximumSum(arr) << endl;
	arr = { 8,-1,6,-7,-4,5,-4,7,-6 };
	cout << sol.maximumSum(arr) << endl;
}
