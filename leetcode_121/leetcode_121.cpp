// leetcode_121.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Best time to buy and sell stock; find out the max profit

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> findMaxProfit(vector<int>& prices, int start, int end) {
		if ((end - start) == 1) {
			if (prices[end] > prices[start])
				return { prices[start], prices[end] - prices[start] };
			else
				return { prices[end], 0 };
		}
		
		vector<int> prevResult = findMaxProfit(prices, start, end-1);
		int prevProfit = prevResult[1];
		int prevMinPrice = prevResult[0];
		int curProfit = prices[end] - prevMinPrice;
		return {(curProfit < 0) ? prices[end] : prevMinPrice, (curProfit > prevProfit) ? curProfit : prevProfit };
	}

	int maxProfit(vector<int>& prices) {
		// v1: brute force, faster than 5.00%
		//int len = prices.size();
		//int maxProfit = 0;
		//for (int i = 0; i < len; ++i) {
		//	for (int j = i + 1; j < len; ++j) {
		//		int profit = prices[j] - prices[i];
		//		if (profit > 0 && profit > maxProfit)
		//			maxProfit = profit;
		//	}
		//}
		//return maxProfit;

		// v2: faster than 14.44% 
		int len = prices.size();
		if (len <= 1)
			return 0;
		vector<int> prevResult = findMaxProfit(prices, 0, len - 1);
		return prevResult[1];
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

