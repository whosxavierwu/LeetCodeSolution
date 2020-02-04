// leetcode_75.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/sort-colors/

/*
Given an array with n objects colored red, white or blue, 
sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 
to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, 
then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		// v1: faster than 100.00%
		//int cnt0 = 0, cnt1 = 0, cnt2 = 0;
		//for (int& num : nums) {
		//	if (num == 0) ++cnt0;
		//	else if (num == 1) ++cnt1;
		//	else if (num == 2) ++cnt2;
		//}
		//int k = 0; 
		//for (int i = 0; i < cnt0; ++i) nums[k++] = 0;
		//for (int i = 0; i < cnt1; ++i) nums[k++] = 1;
		//for (int i = 0; i < cnt2; ++i) nums[k++] = 2;
		
		// v2: faster than 68.88% 
		int tmp = 0, low = 0, mid = 0, high = nums.size() - 1;
		while (mid <= high) {
			if (nums[mid] == 0) {
				tmp = nums[low]; 
				nums[low] = nums[mid]; 
				nums[mid] = tmp;
				++low;
				++mid;
			}
			else if (nums[mid] == 1) {
				++mid;
			}
			else if (nums[mid] == 2) {
				tmp = nums[high];
				nums[high] = nums[mid];
				nums[mid] = tmp;
				--high;
			}
		}
	}
};
int main()
{
    std::cout << "Hello World!\n";
}
