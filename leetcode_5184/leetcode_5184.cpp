// leetcode_5184.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-153/problems/make-array-strictly-increasing/
/*
Given two integer arrays arr1 and arr2, 
return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.

In one operation, 
you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length 
and do the assignment arr1[i] = arr2[j].

If there is no way to make arr1 strictly increasing, return -1.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	//// v1 164 ms: https://leetcode.com/problems/make-array-strictly-increasing/discuss/379095/C%2B%2B-DFS-%2B-Memo
	//short dp[2001][2001] = {};
	//int dfs(vector<int>& arr1, vector<int>& arr2, int i, int j, int prev) {
	//	int len1 = arr1.size();
	//	int len2 = arr2.size();
	//	if (i >= len1) 
	//		return 1;
	//	j = upper_bound(arr2.begin() + j, arr2.end(), prev) - arr2.begin();
	//	if (dp[i][j]) 
	//		return dp[i][j];
	//	// has operation
	//	int r1 = (j < len2) ? (1 + dfs(arr1, arr2, i + 1, j, arr2[j])) : (len2 + 1);
	//	// or no operation
	//	int r2 = (prev < arr1[i]) ? dfs(arr1, arr2, i + 1, j, arr1[i]) : (len2 + 1);
	//	dp[i][j] = min(r1, r2);
	//	return dp[i][j];
	//}
	//int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
	//	sort(arr2.begin(), arr2.end());
	//	int result = dfs(arr1, arr2, 0, 0, INT_MIN);
	//	return result > arr2.size() ? -1 : (result - 1);
	//}

	// v2 https://leetcode.com/problems/make-array-strictly-increasing/discuss/377599/C%2B%2B-20ms-solution
	// 20 ms, faster than 97.73%
	int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
		int len1 = arr1.size();

		// B[i][j] means first i numbers increasing, with cost of j, B[i][j] is the min value of last element.
		vector<vector<int>> B(2, vector<int>(len1 + 1, INT_MAX));

		// sort & drop duplicates in arr2
		sort(arr2.begin(), arr2.end());
		arr2.resize(unique(arr2.begin(), arr2.end()) - arr2.begin());

		B[0][0] = arr1[0]; B[0][1] = arr2[0];  // why?

		int last = 1;
		for (int i = 1; i < len1; ++i) {
			int this_last = -1;
			for (int j = last; j >= 0; --j) {
				int& u = B[(i - 1) % 2][j];
				if (u == INT_MAX) 
					break;
			
				if (u < arr1[i]) {
					B[i % 2][j] = min(B[i % 2][j], arr1[i]);
					this_last = max(this_last, j);
				}

				auto iter = upper_bound(arr2.begin(), arr2.end(), u);
				if (iter != arr2.end()) {
					B[i % 2][j + 1] = min(B[i % 2][j + 1], *iter);
					this_last = max(this_last, j + 1);
				}
				// reset the used B[(i-1)%2][j] 
				u = INT_MAX;
			}
			last = this_last;
		}

		for (int i = 0; i <= len1; ++i)
			if (B[(len1 - 1) % 2][i] != INT_MAX)
				return i;
		return -1;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}
