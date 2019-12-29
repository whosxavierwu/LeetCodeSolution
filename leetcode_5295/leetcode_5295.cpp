// leetcode_5295.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-169/problems/find-n-unique-integers-sum-up-to-zero/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result; 
        if (n % 2 != 0)
            result.push_back(0);
        int t = n / 2;
        for (int i = 1; i <= t; ++i) {
            result.push_back(i);
            result.push_back(-i);
        }
        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
