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


class Solution {
	int partition(vector<int>& nums, int left, int right) {
		int pivot = nums[left];
		int unsplitedLeft = left + 1, unsplitedRight = right;
		while (unsplitedLeft <= unsplitedRight) {
			if (nums[unsplitedLeft] < pivot && nums[unsplitedRight] > pivot) {
				swap(nums[unsplitedLeft], nums[unsplitedRight]);
				++unsplitedLeft;
				--unsplitedRight;
			}
			if (nums[unsplitedLeft] >= pivot)
				++unsplitedLeft;
			if (nums[unsplitedRight] <= pivot)
				--unsplitedRight;
		}
		swap(nums[left], nums[unsplitedRight]);
		return unsplitedRight;
	}
public:
	int findKthLargest(vector<int>& nums, int k) {
		// v1 sort faster than 80.23% 
		//sort(nums.begin(), nums.end());
		//return nums[nums.size() - k];

		// v2 faster than 97.71% 
		//priority_queue<int> pq;
		//for (int num : nums)
		//	pq.push(num);
		//for (int i = 1; i < k; ++i)
		//	pq.pop();
		//return pq.top();

		// v3: 80 ms, faster than 10.47%
		int left = 0, right = nums.size() - 1, kth;
		while (true) {
			int idx = partition(nums, left, right);
			if (idx == k - 1) {
				kth = nums[idx];
				break;
			}
			if (idx < k - 1)
				left = idx + 1;
			else
				right = idx - 1;
		}
		return kth;
	}
};


int main()
{
    std::cout << "Hello World!\n";
}

