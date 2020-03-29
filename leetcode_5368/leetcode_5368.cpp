// leetcode_5368.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-182/problems/find-lucky-integer-in-an-array/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> count(501, 0);
        for (int a : arr)
            count[a]++;
        int result = -1;
        for (int i = 0; i < 501; ++i)
            if (count[i] == i)
                result = i;
        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

