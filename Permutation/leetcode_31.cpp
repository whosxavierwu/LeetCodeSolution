// leetcode_31.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/next-permutation/
/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // v1: 24 ms, faster than 11.72%
        //int n = nums.size();
        //int i = n - 2;
        //while (i >= 0 && nums[i] >= nums[i + 1])
        //    --i;
        //if (i >= 0) {
        //    int j = n - 1;
        //    while (j >= 0 && nums[i] >= nums[j])
        //        --j;
        //    swap(nums[i], nums[j]);
        //}
        //reverse(nums.begin() + i + 1, nums.end());

        // 20 ms, faster than 11.72%
        int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            --i;
        if (i < 0)
            reverse(nums.begin(), nums.end());
        else {
            int j = n - 1;
            while (j >= 0 && nums[i] >= nums[j])
                --j;
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
