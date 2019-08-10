// leetcode_122.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (len <= 1)
			return 0;
		int minprice = prices[0];
		int result = 0;
		for (int i = 1; i < len; i++) {
			if (prices[i] < prices[i - 1]) {
				result += (prices[i - 1] - minprice);
				minprice = prices[i];
			}
		}
		result += (prices[len - 1] - minprice);

		return result;
	}
};
//
//int main()
//{
//    std::cout << "Hello World!\n";
//}
