// leetcode_5308.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-171/problems/minimum-flips-to-make-a-or-b-equal-to-c/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        while ((a | b) != c) {
            int a_or_b_1 = (a | b) & 1;
            int c_1 = c & 1;
            if (a_or_b_1 != c_1) {
                count += 1 + (a & b & 1);
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    // 5:0101  2: 0010  8: 1000
    cout << sol.minFlips(8, 3, 5) << endl;
}
