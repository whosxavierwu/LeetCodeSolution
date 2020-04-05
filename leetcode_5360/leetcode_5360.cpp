// leetcode_5360.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/biweekly-contest-23/problems/count-largest-group/

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        //if (n >= 90)
        //    return 1;
        //if (n < 10)
        //    return n;
        //return min(10 - n / 10, n % 10 + 1);
        unordered_map<int, int> mmap;
        for (int i = 1; i <= n; ++i) {
            int tmp = 0;
            int a = i;
            while (a > 0) {
                tmp += a % 10;
                a /= 10;
            }
            mmap[tmp] += 1;
        }
        int result = 0;
        int maxCount = 0;
        for (auto iter : mmap) {
            if (iter.second > maxCount) {
                maxCount = iter.second;
                result = 1;
            }
            else if (iter.second == maxCount)
                result++;
        }
        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

