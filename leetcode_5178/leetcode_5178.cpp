// leetcode_5178.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-181/problems/four-divisors/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int max_value = 0;
        for (int num : nums)
            if (num > max_value)
                max_value = num;
        int n = max_value + 1;
        vector<int> divisorCount(n, 0);
        int curPrime = 2;
        while (curPrime < n) {
            for (int j = 2; curPrime * j < n; ++j)
                divisorCount[curPrime * j] += 1;
            curPrime++;
        }
        int result = 0;
        for (int num : nums) {
            if (divisorCount[num] == 2) {
                for (int i = 2; i < num; ++i) {
                    if (num % i == 0) {
                        int t = num / i;
                        result = result + 1 + num + i + t;
                        break;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = { 1,2,3,4,5,6,7,8,9,10 };
    cout << sol.sumFourDivisors(nums) << endl;
}
