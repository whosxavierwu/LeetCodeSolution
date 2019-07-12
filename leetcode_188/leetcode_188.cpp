// leetcode_188.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		// v1: DP
		// f[k, i] = max( f[k-1,i], prices[i]-prices[j] + f[k-1,j], ...) {j in [0,i-1]}
		//         = max( f[k-1,i], prices[i]+ max(f[k-1,j]-prices[j]){j in [0,i-1]} )
		// f[k,0]=f[0,i]=0
		int len = prices.size();
		if (len <= 1) return 0;
		int profit = 0;
		vector<vector<int>> f(k+1, vector<int>(len, 0));
		for (int _k = 1; _k <= k; _k++) {
			int tmpMax = f[_k - 1][0] - prices[0];
			for (int i = 1; i < len; i++) {
				f[_k][i] = fmax(f[_k - 1][i], prices[i] + tmpMax);
				tmpMax = fmax(f[_k - 1][i] - prices[i], tmpMax);
				profit = fmax(f[_k][i], profit);
			}
		}
		return profit;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
