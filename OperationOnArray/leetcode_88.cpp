// leetcode_88.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/merge-sorted-array/
/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // beats 100%
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m + n - 1;
        m--;
        n--;
        while (m >= 0 && n >= 0) {
            if (nums1[m] >= nums2[n]) {
                nums1[idx] = nums1[m];
                m--;
                idx--;
            } else {
                nums1[idx] = nums2[n];
                n--;
                idx--;
            }
        }
        if (m >= 0) {
            ;
        } else if (n >= 0) {
            for (; n >= 0; n--) {
                nums1[idx] = nums2[n];
                idx--;
            }
        }
    }
    // beats 16.55%
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp_vec;
        tmp_vec.assign(nums1.begin(), nums1.begin() + m);
        int idx1 = 0, idx2 = 0;
        int idx = 0;
        while (idx1 < m && idx2 < n) {
            if (tmp_vec[idx1] <= nums2[idx2]) {
                nums1[idx] = tmp_vec[idx1];
                idx1++;
            } else {
                nums1[idx] = nums2[idx2];
                idx2++;
            }
            idx++;
        }
        if (idx1 < m) {
            for (int i = idx1; i < m; ++i) {
                nums1[idx] = tmp_vec[i];
                idx++;
            }
        } else if (idx2 < n) {
            for (int i = idx2; i < n; ++i) {
                nums1[idx] = nums2[i];
                idx++;
            }
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
