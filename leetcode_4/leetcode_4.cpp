// leetcode_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/median-of-two-sorted-arrays/
/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 16 ms, faster than 90.98%
        int N1 = nums1.size(), N2 = nums2.size();
        if (N1 < N2)  // make sure nums2 is the shorter one
            return findMedianSortedArrays(nums2, nums1);
        int left = 0, right = N2 * 2;
        while (left <= right) {
            int cut2 = (left + right) / 2;
            int cut1 = N1 + N2 - cut2;
            double L1 = (cut1 == 0) ? INT_MIN : nums1[(cut1 - 1) / 2];
            double L2 = (cut2 == 0) ? INT_MIN : nums2[(cut2 - 1) / 2];
            double R1 = (cut1 == N1 * 2) ? INT_MAX : nums1[cut1 / 2];
            double R2 = (cut2 == N2 * 2) ? INT_MAX : nums2[cut2 / 2];
            if (L1 > R2)
                left = cut2 + 1;
            else if (L2 > R1)
                right = cut2 - 1;
            else
                return (max(L1, L2) + min(R1, R2)) / 2;
        }
        return -1;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
