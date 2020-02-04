// leetcode_322.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/coin-change/
/*
You are given coins of different denominations and a total amount of money amount. 
Write a function to compute the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // v1: 84 ms, faster than 17.21%
        //vector<int> dp(amount + 1, -1);
        //dp[0] = 0;
        //for (int amt = 1; amt <= amount; ++amt)
        //    for (int coin : coins)
        //        if (amt >= coin && dp[amt - coin] != -1)
        //            dp[amt] = dp[amt] > 0 ? min(dp[amt], dp[amt - coin] + 1) : dp[amt - coin] + 1;
        //return dp[amount];

        // v2  92 ms, faster than 14.20%
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int amt = 1; amt <= amount; ++amt)
            for (int coin : coins)
                if (amt >= coin)
                    dp[amt] = min(dp[amt], dp[amt - coin] + 1);
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
