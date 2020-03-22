// leetcode_5350.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/biweekly-contest-22/problems/sort-integers-by-the-power-value/
/*
The power of an integer x is defined as the number of steps needed to transform x into 1 
using the following steps:

if x is even then x = x / 2
if x is odd then x = 3 * x + 1
For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 
(3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).

Given three integers lo, hi and k. 
The task is to sort all integers in the interval [lo, hi] 
by the power value in ascending order, 
if two or more integers have the same power value sort them by ascending order.

Return the k-th integer in the range [lo, hi] sorted by the power value.

Notice that for any integer x (lo <= x <= hi) 
it is guaranteed that x will transform into 1 using these steps 
and that the power of x is will fit in 32 bit signed integer.

Input: lo = 12, hi = 15, k = 2
Output: 13
Explanation: The power of 12 is 9 (12 --> 6 --> 3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1)
The power of 13 is 9
The power of 14 is 17
The power of 15 is 17
The interval sorted by the power value [12,13,14,15]. For k = 2 answer is the second element which is 13.
Notice that 12 and 13 have the same power value and we sorted them in ascending order. Same for 14 and 15.

Input: lo = 1, hi = 1, k = 1
Output: 1

Input: lo = 7, hi = 11, k = 4
Output: 7
Explanation: The power array corresponding to the interval [7, 8, 9, 10, 11] is [16, 3, 19, 6, 14].
The interval sorted by power is [8, 10, 11, 7, 9].
The fourth number in the sorted array is 7.

Input: lo = 10, hi = 20, k = 5
Output: 13

Input: lo = 1, hi = 1000, k = 777
Output: 570

Constraints:

1 <= lo <= hi <= 1000
1 <= k <= hi - lo + 1

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<int> dp(4000, -1);
        dp[1] = 0;
        for (int i = 2; i < 1001; ++i) {
            int now = i;
            int cnt = 0;
            while (now != 1) {
                if (now % 2)
                    now = 3 * now + 1;
                else
                    now /= 2;
                cnt++;
            }
            dp[i] = cnt;
        }
        vector<pair<int, int>> vec;
        for (int i = lo; i <= hi; ++i)
            vec.emplace_back(dp[i], i);
        sort(vec.begin(), vec.end());
        return vec[k - 1].second;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
