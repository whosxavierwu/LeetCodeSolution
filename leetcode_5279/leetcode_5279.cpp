// leetcode_5279.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-166/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

#include <iostream>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        if (n < 10) return 0;
        int product = 1;
        int sum = 0;
        while (n > 0) {
            int a = n % 10;
            product *= a;
            sum += a;
            n /= 10;
        }
        return product - sum;
    }
};

int main()
{
    Solution sol;
    int n = 4421;
    cout << sol.subtractProductAndSum(n) << endl;
}

