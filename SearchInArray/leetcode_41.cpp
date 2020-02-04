// leetcode_41.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/first-missing-positive/
/*
Given an unsorted integer array, find the smallest missing positive integer.

Input: [1,2,0]
Output: 3

Input: [3,4,-1,1]
Output: 2

Input: [7,8,9,11,12]
Output: 1
Note:
Your algorithm should run in O(n) time and uses constant extra space
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // v1: 4 ms, faster than 64.32% 
        int n = nums.size();
        for (int i = 0; i < n; ++i) 
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        for (int i = 0; i < n; ++i)
            if (nums[i] != (i + 1))
                return i + 1;
        return n + 1;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
