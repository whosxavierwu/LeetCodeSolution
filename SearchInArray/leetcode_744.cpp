// SearchInArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/binary-search/
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
int searchLowerBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (left >= 0 && left < nums.size() && nums[left] == target) ? left : -1;
}
int searchUpperBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (target < nums[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return (right >= 0 && right < nums.size() && nums[right] == target) ? right : -1;
}
vector<int> searchRange(vector<int>& nums, int target) {
    int lower = searchLowerBound(nums, target);
    int upper = searchUpperBound(nums, target);
    return { lower, upper };
}

// https://leetcode.com/problems/search-in-rotated-sorted-array/
int searchRotatedSortedArray(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int mid = 0;
    while (left <= right && nums[left] > nums[right]) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[left] == target) return left;
        if (nums[right] == target) return right;
        if (nums[left] < target && target < nums[mid])
            right = mid - 1;
        else if (nums[mid] < target && target < nums[right])
            left = mid + 1;
        else if (nums[left] < nums[mid])
            left = mid + 1;
        else if (nums[mid] < nums[right])
            right = mid - 1;
        else
            return -1;
    }
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (target == nums[mid])
            return mid;
        else if (target < nums[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

class Solution {
public:
    int searchUpperBound(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        // TODO
        return (right >= 0 && right < nums.size() && nums[right] == target) ? right : -1;
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
        
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
