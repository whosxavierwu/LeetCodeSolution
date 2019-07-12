// leetcode_188.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(int K, vector<int>& prices) {
		// v1: DP, seems it cost too much memory! k may be 1000000000
		// f[k, i] = max( f[k-1,i], prices[i]-prices[j] + f[k-1,j], ...) {j in [0,i-1]}
		//         = max( f[k-1,i], prices[i]+ max(f[k-1,j]-prices[j]){j in [0,i-1]} )
		// f[k,0]=f[0,i]=0
		//int len = prices.size();
		//if (len <= 1)
		//	return 0;
		//int profit = 0;
		//vector<vector<int>> f(K + 1, vector<int>(len, 0));
		//for (int k = 1; k <= K; ++k) {
		//	// use tmpMax to find out max(f[k-1, j] - prices[j]) {j in [0,i-1]}
		//	int tmpMax = f[k - 1][0] - prices[0];
		//	for (int i = 1; i < len; ++i) {
		//		f[k][i] = fmax(f[k][i - 1], prices[i] + tmpMax);
		//		tmpMax = fmax(f[k - 1][i] - prices[i], tmpMax);
		//		profit = fmax(f[k][i], profit);
		//	}
		//}
		//return profit;
		
		// v2: DP, still too slow.... TLE
		//int len = prices.size();
		//if (len <= 1) return 0;
		//int profit = 0;
		//vector<int> prevProfits(len, 0);  // previous profits, means [k-1][i]
		//for (int _k = 1; _k <= K; _k++) {
		//	int tmpMax = - prices[0];
		//	for (int i = 1; i < len; i++) {
		//		// prevProfits[i-1] == f[k][i-1]
		//		int cur = fmax(prevProfits[i-1], prices[i] + tmpMax);
		//		// prevProfits[i] == f[k-1][i]
		//		tmpMax = fmax(prevProfits[i] - prices[i], tmpMax);
		//		profit = fmax(cur, profit);
		//		prevProfits[i] = cur;
		//	}
		//}
		//return profit;

		// v3: MLE, it succeed in #123
		//vector<int> profitBuy(K+1, INT_MIN);
		//vector<int> profitSell(K+1, 0);
		//for (int price : prices) {  
		//	for (int k = K; k >= 1; --k) {
		//		profitSell[k] = fmax(profitBuy[k] + price, profitSell[k]);
		//		profitBuy[k] = fmax(profitSell[k - 1] - price, profitBuy[k]);
		//	}
		//}
		//return profitSell[K];

		// f[k, i] = max( f[k-1,i], prices[i]-prices[j] + f[k-1,j], ...) {j in [0,i-1]}
		//         = max( f[k-1,i], prices[i]+ max(f[k-1,j]-prices[j]) {j in [0,i-1]} )
		// f[k,0]=f[0,i]=0

		// v4: GREAT jobs!!! faster than 98.81%
		int len = prices.size();
		if (len <= 1) return 0;
		// really important!!! 
		if (K > len / 2) { 
			int ans = 0;
			for (int i = 1; i < len; ++i) 
				ans += fmax(prices[i] - prices[i - 1], 0);
			return ans;
		}
		int profit = 0;
		vector<int> prevprofits(len, 0);  // previous profits, means [k-1][i]
		for (int _k = 1; _k <= K; _k++) {
			int tmpmax = - prices[0];
			for (int i = 1; i < len; i++) {
				// prevprofits[i-1] == f[k][i-1]
				int cur = fmax(prevprofits[i-1], prices[i] + tmpmax);
				// prevprofits[i] == f[k-1][i]
				tmpmax = fmax(prevprofits[i] - prices[i], tmpmax);
				profit = fmax(cur, profit);
				prevprofits[i] = cur;
			}
		}
		return profit;

	}
};

int main()
{
    std::cout << "Hello World!\n";
}
