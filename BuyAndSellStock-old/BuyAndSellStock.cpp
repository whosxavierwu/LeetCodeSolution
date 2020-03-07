#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock
// buy one and sell one share of the stock
int maxProfit(vector<int>& prices) {
    int runMin = prices[0];
    int maxProfit = 0;
    for (int price : prices) {
        maxProfit = max(maxProfit, price - runMin);
        runMin = min(price, runMin);
    }
    return maxProfit;
}

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// buy one and sell one share of the stock multiple times
int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len <= 1) return 0;
    int minPrice = prices[0];
    int profit = 0;
    for (int i = 1; i < len; ++i) {
        if (prices[i - 1] > prices[i]) {
            // always sell before price goes down
            profit += (prices[i - 1] - minPrice);
            minPrice = prices[i];
        }
    }
    profit += (prices[len - 1] - minPrice);
}

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// You may complete at most two transactions.
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int costBuyOne = INT_MIN, costBuyTwo = INT_MIN;
    int profitSellOne = 0, profitSellTwo = 0;
    for (int price : prices) {
        profitSellTwo = max(profitSellTwo, costBuyTwo + price);
        costBuyTwo = max(costBuyTwo, profitSellOne - price);
        profitSellOne = max(profitSellOne, costBuyOne + price);
        costBuyOne = max(costBuyOne, -price);
    }
    return profitSellTwo;
}

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// You may complete at most k transactions.
int maxProfit(int K, vector<int>& prices) {
    int n = prices.size();
    int profit = 0;
    if (n <= 1) return 0;
    if (K > n / 2) {
        for (int i = 1; i < n; ++i)
            profit += max(prices[i] - prices[i - 1], 0);
        return profit;
    }
    vector<int> prevProfitSell(n, 0);
    for (int k = 1; k <= K; ++k) {
        int profitBuy = -prices[0];
        for (int i = 1; i < n; ++i) {
            int profitSell = max(prevProfitSell[i - 1], profitBuy + prices[i]);
            profitBuy = max(prevProfitSell[i] - prices[i], profitBuy);
            profit = max(profit, profitSell);
            prevProfitSell[i] = profitSell;
        }
    }
}

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// You may complete as many transactions as you like
// After you sell your stock, you cannot buy stock on next day
int maxProfit(vector<int>& prices) {

}

int main()
{
    cout << "Hello World!\n";
}
