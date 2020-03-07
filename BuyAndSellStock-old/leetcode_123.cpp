// leetcode_123.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Design an algorithm to find the maximum profit. You may complete at most two transactions.

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		// v1: awesome... beats 98% 
		// note: using fmax is much faster than if statement
		// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/39611/Is-it-Best-Solution-with-O(n)-O(1).
		//int costBuyOne = INT_MIN, costBuyTwo = INT_MIN;
		//int profitSellOne = 0, profitSellTwo = 0; 
		//for (int price : prices) {  // Assume we only have 0 money at first
		//	// principle: when we buy, cost goes up; when we sell, profit goes up.
		//	// so when we buy, minimize cost, when we sell, maximize profit
		//	// if we have two stock, and now sell, find out the max profit
		//	profitSellTwo = fmax(costBuyTwo + price, profitSellTwo);
		//	// if we have one stock, and now buy, find out the min cost
		//	costBuyTwo = fmax(profitSellOne - price, costBuyTwo);
		//	// if we have one stock, and now sell, find out the max profit
		//	profitSellOne = fmax(costBuyOne + price, profitSellOne);
		//	// if we have no stock, and now buy, find out the min cost
		//	costBuyOne = fmax(0 - price, costBuyOne);
		//}
		//return profitSellTwo;

		// v2: note, the initialization of variables make sense!
		// we always want to maximize the profit
		// so the buying actions are also consider as profit, though it adds a negative value to profit
		 // initially, we dont have any stock, so the profit is MIN
		//int profitOfBuyOne = INT_MIN, profitOfBuyTwo = INT_MIN;
		//int profitOfSellOne = 0, profitOfSellTwo = 0;
		//for (int price : prices) {
		//	// when we sell, new profit = previous profit + price
		//	// when we buy, new profit = previous profit - price 
		//	profitOfSellTwo = (profitOfBuyTwo + price > profitOfSellTwo) ? profitOfBuyTwo + price : profitOfSellTwo;
		//	profitOfBuyTwo = (profitOfSellOne - price > profitOfBuyTwo)? profitOfSellOne - price : profitOfBuyTwo;
		//	profitOfSellOne = (profitOfBuyOne + price > profitOfSellOne)? profitOfBuyOne + price: profitOfSellOne;
		//	profitOfBuyOne = (-price > profitOfBuyOne)? -price: profitOfBuyOne;
		//}
		//return profitOfSellTwo;

		// v3: DP, beats 80%
		// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/39608/A-clean-DP-solution-which-generalizes-to-k-transactions
		// f[k, i] = max profit until prices[i]
		// f[k, i] = max(f[k, i-1], prices[i] - prices[j] + f[k-1, j]) {j in [0, i-1]}
		//         = max( f[k, i-1], prices[i] + max(f[k-1, j] - prices[j]) )
		// f[k, 0] = f[0, i] = 0
		//int len = prices.size();
		//if (len <= 1)
		//	return 0;
		//int K = 2;  // at most K transactions
		//int profit = 0;
		//vector<vector<int>> f(K+1, vector<int>(len, 0));
		//for (int k = 1; k <= K; ++k) {
		//	// use tmpMax to find out max(f[k-1, j] - prices[j]) {j in [0,i-1]}
		//	int tmpMax = f[k - 1][0] - prices[0];
		//	for (int i = 1; i < len; ++i) {
		//		f[k][i] = fmax(f[k][i-1], prices[i] + tmpMax);
		//		tmpMax = fmax(f[k - 1][i] - prices[i], tmpMax);
		//		profit = fmax(f[k][i], profit);
		//	}
		//}
		//return profit;

		// v4
		//int K = 2;
		//vector<int> profitBuy(K+1, INT_MIN);
		//vector<int> profitSell(K+1, 0);
		//for (int price : prices) {  
		//	for (int k = K; k >= 1; --k) {
		//		profitSell[k] = fmax(profitBuy[k] + price, profitSell[k]);
		//		profitBuy[k] = fmax(profitSell[k - 1] - price, profitBuy[k]);
		//	}
		//}
		//return profitSell[K];

		// v5
		int K = 2;
		vector<int> profitBuy(K + 1, INT_MIN);
		vector<int> profitSell(K + 1, 0);
		for (int price : prices) {
			for (int k = 1; k <= K; ++k) {
				profitBuy[k] = fmax(profitSell[k - 1] - price, profitBuy[k]);
				profitSell[k] = fmax(profitBuy[k] + price, profitSell[k]);
			}
		}
		return profitSell[K];
	}
};
//
//int main()
//{
//	vector<int> prices = { 3,3,5,0,0,3,1,4 };
//	Solution sol;
//	int profit = sol.maxProfit(prices);
//	cout << profit << endl;
//	return 0;
//}
