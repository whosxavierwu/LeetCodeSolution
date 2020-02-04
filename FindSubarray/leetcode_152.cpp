// leetcode_152.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/maximum-product-subarray/
/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) 
which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // v1: 4 ms, faster than 89.24%
        int n = nums.size();
        int result = nums[0];
        int imin = result, imax = result;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < 0) swap(imax, imin);
            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]);
            result = max(result, imax);
        }
        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
