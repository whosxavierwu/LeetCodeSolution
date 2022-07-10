// leetcode_287.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/find-the-duplicate-number/
/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. 
Assume that there is only one duplicate number, find the duplicate one.

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate1(vector<int>& nums) {  // 205ms
        int p_step1 = nums[0];
        int p_step2 = nums[0];
        // find some point in the cycle
        do {
            p_step1 = nums[p_step1];
            p_step2 = nums[nums[p_step2]];
        } while (p_step1 != p_step2);
        // find the entrance to the cycle 
        // why does this work???
        int entry = nums[0];
        while (entry != p_step1) {
            entry = nums[entry];
            p_step1 = nums[p_step1];
        }
        return entry;
    }
    int findDuplicate2(vector<int>& nums) {  // 177ms
        int n = nums.size() - 1;
        int left = 1, right = n;
        while (left < right) {
            int a = (right - left + 1) % 2;
            int mid = (left + right) / 2;
            int lCnt = 0, rCnt = 0;
            if (a == 1) {
                int mCnt = 0;
                for (int num: nums) {
                    if (num < left || num > right)
                        continue;
                    lCnt += (num < mid);
                    rCnt += (num > mid);
                    mCnt += (num == mid);
                    if (mCnt > 1) {
                        return mid;
                    }
                }
                if (lCnt > rCnt) {
                    right = mid - 1;
                } else {  // lCnt < rCnt
                    left = mid + 1;
                }
            } else {
                for (int num: nums) {
                    if (num < left || num > right)
                        continue;
                    lCnt += (num <= mid);
                    rCnt += (num > mid);
                }
                if (lCnt > rCnt) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
        }
        return left;
    }
};
int main()
{
    std::cout << "Hello World!\n";
}
