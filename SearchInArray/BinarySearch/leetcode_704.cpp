// leetcode_704.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/binary-search/
// Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. 
// If target exists, then return its index, otherwise return -1.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int binarySearch(const vector<int>& nums, int start, int end, const int& target) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
