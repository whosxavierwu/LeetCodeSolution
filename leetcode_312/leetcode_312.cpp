// leetcode_312.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/burst-balloons/
/*
Given n balloons, indexed from 0 to n-1. 
Each balloon is painted with a number on it represented by array nums. 
You are asked to burst all the balloons. 
If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. 
Here left and right are adjacent indices of i.
After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Input: [3,1,5,8]
Output: 167
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
			 coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ¡Ü n ¡Ü 500, 0 ¡Ü nums[i] ¡Ü 100
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxCoins(vector<int>& iNums) {
		// faster than 89.46%
		// https://leetcode.com/problems/burst-balloons/discuss/76228/Share-some-analysis-and-explanations
		
		vector<int> nums;
		// consider only positive number
		nums.push_back(1);
		for (int x : iNums) if (x > 0) nums.push_back(x);
		nums.push_back(1);

		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(n));  // the maxCoins from i to j
		for (int len = 2; len < n; ++len) {  // set a len of window
			for (int left = 0; left < n - len; ++left) {  // slide the window
				int right = left + len;
				// note: we dont set finalBallon=left or right, we keep left & right with finalBallon
				for (int finalBalloon = left + 1; finalBalloon < right; ++finalBalloon) {
					dp[left][right] = max(dp[left][right], 
						nums[left] * nums[finalBalloon] * nums[right] + dp[left][finalBalloon] + dp[finalBalloon][right]);
				}
			}
		}
		return dp[0][n - 1];
	}
};
int main()
{
    std::cout << "Hello World!\n";
}
