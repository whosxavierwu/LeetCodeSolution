// leetcode_96.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/unique-binary-search-trees/
/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
*/

#include <iostream>
#include <vector>
using namespace std;

// v1: faster than 56.93%
//class Solution {
//public:
//	int numTrees(int start, int end) {
//		if (start == end)
//			return 1;
//		if (start + 1 == end)
//			return 2;
//		int result = 0;
//		result += numTrees(start + 1, end);
//		result += numTrees(start, end - 1);
//		for (int i = start + 1; i < end; ++i) {
//			result += numTrees(start, i - 1) * numTrees(i + 1, end);
//		}
//		return result;
//	}
//	int numTrees(int n) {
//		return numTrees(1, n);
//	}
//};

// v2 faster than 56.93%, less than 100.00%
//class Solution {
//public:
//	int numTrees(int n) {
//		if (n == 0) return 0;
//		if (n == 1) return 1;
//		int result = 0;
//		result += 2 * numTrees(n - 1);
//		for (int i = 1; i < n - 1; ++i) {
//			result += numTrees(i) * numTrees(n - 1 - i);
//		}
//		return result;
//	}
//};

// v3 faster than 100.00%
class Solution {
public:
	int numTrees(int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;
		vector<int> result(n+1, 0);
		result[1] = 1;
		for (int k = 2; k <= n; ++k) {
			result[k] = 2 * result[k - 1];
			for (int i = 1; i < k - 1; ++i) {
				result[k] += result[i] * result[k - 1 - i];
			}
		}
		return result[n];
	}
};

int main()
{
	Solution sol;
	int prev = 0;
	for (int i = 1; i <= 10; ++i) {
		int cur = sol.numTrees(i);
		cout << i << ": " << cur << " = " << prev << " + " << cur-prev << endl;
		prev = cur;
	}
	return 0;
}
