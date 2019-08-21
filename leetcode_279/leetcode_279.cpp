// leetcode_279.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/perfect-squares/
/*
Given a positive integer n, 
find the least number of perfect square numbers 
(for example, 1, 4, 9, 16, ...) which sum to n.

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int is_square(int n) {
		int sqrt_n = (int)sqrt(n);
		return (sqrt_n * sqrt_n == n);
	}
	int numSquares(int n) {
		// v1: 104 ms, faster than 54.69% 
		//if (n <= 0) return 0;
		//vector<int> dp(n + 1, INT_MAX);
		//dp[0] = 0;
		//for (int i = 1; i <= n; ++i) {
		//	for (int j = 1; j * j <= i; ++j) {
		//		dp[i] = min(dp[i], dp[i - j * j] + 1);
		//	}
		//}
		//return dp.back();

		// v2: 8 ms, faster than 90.37%
		//if (n <= 0) return 0;
		//static vector<int> dp({ 0 });
		//while (dp.size() <= n) {
		//	int m = dp.size();
		//	int cnt = INT_MAX;
		//	for (int i = 1; i * i <= m; ++i)
		//		cnt = min(cnt, dp[m - i * i] + 1);
		//	dp.push_back(cnt);
		//}
		//return dp[n];

		// v3  0 ms, faster than 100.00% 
		// Based on Lagrange's Four Square theorem, there are only 4 possible results: 1, 2, 3, 4.
		if (is_square(n)) return 1;
		// The result is 4 if and only if n can be written in the 
		// form of 4^k*(8*m + 7). Please refer to 
		// Legendre's three-square theorem.
		while ((n & 3) == 0) {  // n%4==0
			n >>= 2;
		}
		if ((n & 7) == 7) {  // // n%8 == 7
			return 4;
		}
		int sqrt_n = (int)sqrt(n);
		for (int i = 1; i <= sqrt_n; ++i) {
			if (is_square(n - i * i)) {
				return 2;
			}
		}
		return 3;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}
