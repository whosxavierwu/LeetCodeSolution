// leetcode_215.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		// v1 sort faster than 80.23% 
		//sort(nums.begin(), nums.end());
		//return nums[nums.size() - k];

		// v2 faster than 97.71% 
		priority_queue<int> pq;
		for (int num : nums)
			pq.push(num);
		for (int i = 1; i < k; ++i)
			pq.pop();
		return pq.top();
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

