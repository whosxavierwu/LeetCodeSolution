// leetcode_309.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

Example:

Input: [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		// faster than 76.49% 
		// ending buy or ending sell
		int buy = INT_MIN, sell = 0, prev_sell = 0, prev_buy = 0;
		for (int price : prices) {
			prev_buy = buy;
			buy = max(prev_sell - price, buy);
			prev_sell = sell;
			sell = max(prev_buy + price, sell);
		}
		return sell;
	}
};
//
//int main()
//{
//    std::cout << "Hello World!\n";
//}
