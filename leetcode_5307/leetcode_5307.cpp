// leetcode_5307.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-171/problems/convert-integer-to-the-sum-of-two-no-zero-integers/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasZero(int x) {
        if (x == 0) 
            return true;
        while (x > 0) {
            int i = x % 10;
            if (i == 0)
                return true;
            x /= 10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; ++a) {
            int b = n - a;
            if (!(hasZero(a) || hasZero(b)))
                return { a, b };
        }
        return {};
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
