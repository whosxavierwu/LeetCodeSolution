// leetcode_1104.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> pathInZigZagTree(int label) {
		//// v1: recursive  4 ms, faster than 58.85%
		//if (label == 1) return { 1 };
		//int k = 1;
		//for (; (1 << k) <= label; ++k);
		//--k;
		//int parent = (1 << k) - 1 - (label - (1 << k)) / 2;
		//vector<int> result = pathInZigZagTree(parent);
		//result.push_back(label);
		//return result;

		// v2: 0 ms, faster than 100.00%  8.4 MB, less than 100.00% 
		vector<int> result;
		int k = 1;
		for (; (1 << k) <= label; ++k);
		--k;
		int cur = label;
		for (; k >= 0; --k) {
			result.push_back(cur);
			cur = (1 << k) - 1 - (cur - (1 << k)) / 2;
		}
		reverse(result.begin(), result.end());
		return result;
	}
};

int main()
{
	Solution sol;
	vector<int> result = sol.pathInZigZagTree(26);
	for (int a : result)
		cout << a << " ";
	cout << endl;
}
