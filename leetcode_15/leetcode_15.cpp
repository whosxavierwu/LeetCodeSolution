// leetcode_15.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 3Sum, find out triplets that sum to zero.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int binarySearch(vector<int>& nums, int start, int end, int target) {
		int mid = start;
		while (start <= end) {
			mid = (start + end) / 2;
			// to avoid overflow: 
			//mid = start + (end - start) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
				start = mid + 1;
			else
				end = mid - 1;
		}
		return -1;
	}

	vector<vector<int>> twoSum(vector<int>& numbers, int start, int end, int target) {
		vector<vector<int>> result(0);
		int tmp = 0;
		for (int i = start; i <= (end-2); ++i) {
			tmp = binarySearch(numbers, i + 1, end, target - numbers[i]);
			if (tmp >= 0) 
				result.push_back({numbers[i], numbers[tmp]});
		}
		return result;
	}

	vector<vector<int>> threeSum(vector<int>& nums) {
		// v1: refer to twoSum from #167
		// we have problem! The solution set must not contain duplicate triplets
		int len = nums.size();
		vector<vector<int>> results(0);
		for (int i = 0; i <= (len-3); ++i) {
			vector<vector<int>> twins = twoSum(nums, i + 1, len - 1, -nums[i]);
			for (vector<int> twin : twins) {
				results.push_back({ nums[i], twin[0], twin[1] });
			}
		}
		return results;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

