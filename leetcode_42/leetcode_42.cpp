// leetcode_42.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/trapping-rain-water/
/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	
	int trap(vector<int>& height) {
		// v1: faster than 61.31% 
		//int len = height.size();
		//if (len <= 2) return 0;
		//int result = 0;
		//vector<int> lMax(len);
		//vector<int> rMax(len);
		//for (int i = 1; i < len; ++i)
		//	lMax[i] = height[i - 1] > lMax[i - 1] ? height[i - 1] : lMax[i - 1];
		//for (int i = len - 2; i >= 0; --i)
		//	rMax[i] = height[i + 1] > rMax[i + 1] ? height[i + 1] : rMax[i + 1];
		//for (int i = 0; i < len; ++i) {
		//	int tmp = min(lMax[i], rMax[i]) - height[i];
		//	if (tmp > 0) result += tmp;
		//}
		//return result;

		//v2: faster than 61.31%
		int len = height.size();
		if (len <= 2) return 0;
		int result = 0;
		vector<int> rMax(len);
		for (int i = len - 2; i >= 0; --i)
			rMax[i] = height[i + 1] > rMax[i + 1] ? height[i + 1] : rMax[i + 1];
		int lMax = 0;
		for (int i = 0; i < len; ++i) {
			if (i > 0 && height[i - 1] > lMax)
				lMax = height[i - 1];
			int tmp = min(lMax, rMax[i]) - height[i];
			if (tmp > 0) result += tmp;
		}
		return result;
	}
};
int main()
{
	Solution sol;
	vector<int> arr = { 5,2,1,2,1,5 };
	//vector<int> arr = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	int result = sol.trap(arr);
	cout << result << endl;
	return 0;
}
