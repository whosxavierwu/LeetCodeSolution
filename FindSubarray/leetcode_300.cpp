// leetcode_300.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/longest-increasing-subsequence/
/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Note:

There may be more than one LIS combination, 
it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // v3: 0 ms, faster than 100.00%
        vector<int> vec;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            auto iter = lower_bound(vec.begin(), vec.end(), nums[i]);
            if (iter == vec.end())
                vec.push_back(nums[i]);
            else
                *iter = nums[i];
        }
        return vec.size();
    }
};

int main()
{
    vector<int> nums = { 10,9,2,5,3,7,101,18 };
    Solution sol;
    vector<int> result = sol.lengthOfLIS(nums);
    return 0;
}
