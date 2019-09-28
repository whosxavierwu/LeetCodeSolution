// leetcode_5182.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-153/problems/maximum-subarray-sum-with-one-deletion/
/*
Given an array of integers, 
return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. 

In other words, 
you want to choose a subarray and optionally delete one element from it 
so that there is still at least one element left and the sum of the remaining elements is maximum possible.

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

		// v2: 44 ms, faster than 60.88% 
		//int len = arr.size();
		//int curMaxSum, allMaxSum;

		//vector<int> leftMaxSum(len);
		//curMaxSum = allMaxSum = leftMaxSum[0] = arr[0];
		//for (int i = 1; i < len; ++i) {
		//	curMaxSum = max(arr[i], curMaxSum + arr[i]);
		//	allMaxSum = max(allMaxSum, curMaxSum);
		//	leftMaxSum[i] = curMaxSum;
		//}

		//vector<int> rightMaxSum(len);
		//curMaxSum = allMaxSum = rightMaxSum[len - 1] = arr[len - 1];
		//for (int i = len - 2; i >= 0; i--) {
		//	curMaxSum = max(arr[i], curMaxSum + arr[i]);
		//	allMaxSum = max(allMaxSum, curMaxSum);
		//	rightMaxSum[i] = curMaxSum;
		//}

		//int result = allMaxSum;
		//for (int i = 1; i < len - 1; ++i)
		//	result = max(result, leftMaxSum[i - 1] + rightMaxSum[i + 1]);
		//return result;

		// v3:  40 ms, faster than 88.25%
		//int len = arr.size();
		//int allMaxSum = arr[0];

		//vector<int> leftMaxSum(len);
		//vector<int> rightMaxSum(len);
		//leftMaxSum[0] = arr[0];
		//rightMaxSum[len - 1] = arr[len - 1];

		//int curLeftMaxSum = arr[0];
		//int curRightMaxSum = arr[len - 1];
		//for (int i = 1; i < len; ++i) {
		//	curLeftMaxSum = max(arr[i], curLeftMaxSum + arr[i]);
		//	allMaxSum = max(allMaxSum, curLeftMaxSum);
		//	leftMaxSum[i] = curLeftMaxSum;

		//	int j = len - 1 - i;
		//	curRightMaxSum = max(arr[j], curRightMaxSum + arr[j]);
		//	allMaxSum = max(allMaxSum, curRightMaxSum);
		//	rightMaxSum[j] = curRightMaxSum;
		//}

		//int result = allMaxSum;
		//for (int i = 1; i < len - 1; ++i)
		//	result = max(result, leftMaxSum[i - 1] + rightMaxSum[i + 1]);
		//return result;

		// v4: 44 ms, faster than 60.88%, why is it slower????
		int result = INT_MIN;
		int sum1 = 0, sum2 = 0, min1 = 0, min2 = 0;
		for (int val : arr) {
			if (sum1 < 0) sum1 = min1 = 0;
			if (sum2 <= min2) sum2 = min2 = 0;
			sum1 += val;
			sum2 += val;
			// always ignore the min number 
			result = max({ result, sum1 - min1, sum2 - min2 });
			min1 = min(min1, val);
			min2 = min(min2, val);
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
