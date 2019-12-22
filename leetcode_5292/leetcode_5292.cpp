// leetcode_5292.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-168/problems/divide-array-in-sets-of-k-consecutive-numbers/
/*
Given an array of integers nums and a positive integer k, 
find whether it's possible to divide this array into sets of k consecutive numbers
Return True if its possible otherwise return False.

Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].

Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
Output: true
Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].

Input: nums = [3,3,2,2,1,1], k = 3
Output: true

Input: nums = [1,2,3,4], k = 3
Output: false
Explanation: Each array should be divided in subarrays of size 3.

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
1 <= k <= nums.length
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;
        set<int> sset;
        map<int, int> mmap;
        for (int num : nums) {
            sset.insert(num);
            mmap[num]++;
        }
        for (int i : sset) {
            if (mmap[i] == 0) continue;
            int cnt = mmap[i];
            for (int j = 0; j < k; ++j) {
                if (mmap[i + j] < cnt) 
                    return false;
                else
                    mmap[i + j] -= cnt;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = { 3,3,2,2,1,1 };
    int k = 3;
    cout << sol.isPossibleDivide(nums, k) << endl;
}
