// leetcode_5291.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-168/problems/find-numbers-with-even-number-of-digits/
/*

Given an array nums of integers, return how many of them contain an even number of digits.


Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation:
12 contains 2 digits (even number of digits).
345 contains 3 digits (odd number of digits).
2 contains 1 digit (odd number of digits).
6 contains 1 digit (odd number of digits).
7896 contains 4 digits (even number of digits).
Therefore only 12 and 7896 contain an even number of digits.
Example 2:

Input: nums = [555,901,482,1771]
Output: 1
Explanation:
Only 1771 contains an even number of digits.


Constraints:

1 <= nums.length <= 500
1 <= nums[i] <= 10^5
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int a : nums) {
            bool isEven = true;
            while (a > 0) {
                a = a / 10;
                isEven = !isEven;
            }
            if (isEven)
                ++count;
        }
        return count;
    }
};

int main()
{
    vector<int> a = { 12,345,2,6,7896 };
    Solution sol;
    cout << sol.findNumbers(a) << endl;
}
