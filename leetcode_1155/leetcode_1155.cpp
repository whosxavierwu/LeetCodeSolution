// leetcode_1155.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int numRollsToTarget(int d, int f, int target) {
		// v1: TLE
		//if (d == 1) return target <= f;
		//long result = 0;
		//for (int i = 1; i <= f; ++i) {
		//	int newTarget = target - i;
		//	if (newTarget < (d - 1)) break;
		//	if (newTarget > (d - 1) * f) continue;
		//	result += numRollsToTarget(d - 1, f, newTarget);
		//}
		//return result % 1000000007;

		// v2 todo
		vector<vector<long>> dp(d + 1, vector<long>(target + 1));
		for (int _f = 1; _f <= f; ++_f)
			dp[1][_f] = 1;
		for (int _d = 2; _d <= d; ++_d) {
			for (int _t = _d; _t <= target; ++_t) {
				long sum = 0;
				for (int _f = 1; _f <= f && _f < _t; ++_f) {
					sum += (dp[_d - 1][_t - _f]) % 1000000007;
				}
				dp[_d][_t] = sum % 1000000007;
			}
		}
		return dp[d][target] ;
	}
};

int main()
{
	Solution sol;
	int result = 0; 
	//result = sol.numRollsToTarget(1, 6, 3);
	//cout << result << endl;
	//result = sol.numRollsToTarget(2, 6, 7);
	//cout << result << endl;
	//result = sol.numRollsToTarget(2, 5, 10);
	//cout << result << endl;
	//result = sol.numRollsToTarget(1, 2, 3);
	//cout << result << endl;
	result = sol.numRollsToTarget(30, 30, 500);
	cout << result << endl;
}
