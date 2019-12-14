// leetcode_5126.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://leetcode.com/contest/biweekly-contest-15/problems/element-appearing-more-than-25-in-sorted-array/
/*
Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time.

Return that integer.



Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6


Constraints:

1 <= arr.length <= 10^4
0 <= arr[i] <= 10^5
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] == arr[i - 1])
                ++cnt;
            else {
                cnt = 1;
            }
            if (cnt > n / 4)
                return arr[i];
        }
        return 1;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

