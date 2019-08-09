// leetcode_11.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/container-with-most-water/
/*
Given n non-negative integers a1, a2, ..., an , 
where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 

Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		// v1: faster than 13.83%
		//int len = height.size();
		//int maxArea = 0;
		//for (int i = 0; i < len; ++i) {
		//	for (int j = i + 1; j < len; ++j) {
		//		int tmp = min(height[i], height[j]) * (j - i);
		//		if (tmp > maxArea) maxArea = tmp;
		//	}
		//}
		//return maxArea;

		//  v2 faster than 19.54%
		//int len = height.size();
		//int maxArea = 0;
		//for (int i = 0; i < len; ++i) {
		//	for (int j =len-1; j > i; --j) {
		//		int tmp = min(height[i], height[j]) * (j - i);
		//		if (tmp > maxArea) maxArea = tmp;
		//		if (height[j] >= height[i]) break;
		//	}
		//}
		//return maxArea;

		// v3 faster than 68.17% 
		//int maxArea = 0, left = 0, right = height.size() - 1;
		//while (left < right) {
		//	int area = min(height[left], height[right]) * (right - left);
		//	if (area > maxArea) maxArea = area;
		//	// climb
		//	if (height[left] < height[right]) ++left;
		//	else --right;
		//}
		//return maxArea;

		// v4: faster than 68.17% 
		//int maxArea = 0, left = 0, right = height.size() - 1;
		//while (left < right) {
		//	int h = min(height[left], height[right]);
		//	int area = h * (right - left);
		//	if (area > maxArea) maxArea = area;
		//	while (height[left] <= h && left < right) ++left;
		//	while (height[right] <= h && left < right) --right;
		//}
		//return maxArea;

		// v5 faster than 31.95% 
		int maxArea = 0, left = 0, right = height.size() - 1;
		while (left < right) {
			maxArea = max(maxArea, min(height[left], height[right]) * (right - left));
			(height[left] < height[right]) ? left++ : right--;
		}
		return maxArea;
	}
};
int main()
{
	vector<int> height = { 1,8,6,2,5,4,8,3,7 };
	Solution sol;
	int result = sol.maxArea(height);
	cout << result << endl;
	return 0;
}
