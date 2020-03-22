// leetcode_5351.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/biweekly-contest-22/problems/pizza-with-3n-slices/
/*
There is a pizza with 3n slices of varying size, 
you and your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick next slice in anti clockwise direction of your pick.
Your friend Bob will pick next slice in clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Sizes of Pizza slices is represented by circular array slices in clockwise direction.

Return the maximum possible sum of slice sizes which you can have.

Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, 
Alice and Bob will pick slices with size 3 and 5 respectively. 
Then Pick slices with size 6, 
finally Alice and Bob will pick slice of size 2 and 1 respectively. 
Total = 4 + 6.

Input: slices = [8,9,8,6,1,1]
Output: 16
Output: Pick pizza slice of size 8 in each turn. If you pick slice with size 9 your partners will pick slices of size 8.

Input: slices = [4,1,2,5,8,3,1,9,7]
Output: 21

Input: slices = [3,1,2]
Output: 3


Constraints:

1 <= slices.length <= 500
slices.length % 3 == 0
1 <= slices[i] <= 1000
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        slices.insert(slices.end(), slices.begin(), slices.end());
        vector<vector<int>> dp(2 * n, vector<int>(2 * n + 1, -1e9));
        for (int i = 0; i < 2 * n; ++i)
            dp[i][i] = 0;
        for (int d = 0; d < n + 1; ++d) {
            if (d % 3 == 0) {
                for (int left = 0; left < n; ++left) {
                    int right = left + d;
                    int tmp = 0;
                    for (int c = left; c < right; ++c) {
                        tmp = dp[left][c] + dp[c][right];
                        if (dp[left][right] < tmp)
                            dp[left][right] = tmp;
                    }
                    for (int c = left + 1; c < right - 1; ++c) {
                        tmp = dp[left + 1][c] + slices[c] + dp[c + 1][right - 1];
                        if (dp[left][right] < tmp)
                            dp[left][right] = tmp;
                    }
                }
            }
        }
        int ret = 0;
        for (int left = 0; left < n + 1; ++left)
            ret = max(ret, dp[left][left + n]);
        return ret;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
