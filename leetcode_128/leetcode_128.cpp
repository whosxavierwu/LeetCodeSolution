// leetcode_128.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/longest-consecutive-sequence/
/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 12 ms, faster than 68.62% 
        unordered_set<int> sset(nums.begin(), nums.end());
        int result = 0;
        for (int num : nums) {
            if (sset.find(num) == sset.end())
                continue;
            sset.erase(num);
            int prev = num - 1, next = num + 1;
            while (sset.find(prev) != sset.end()) {
                sset.erase(prev);
                prev--;
            }
            while (sset.find(next) != sset.end()) {
                sset.erase(next);
                next++;
            }
            result = max(result, next - prev - 1);
        }
        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
