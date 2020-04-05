// leetcode_5195.cpp : This file contains the 'main' function. Program execution begins and ends there.
// todo https://leetcode.com/contest/weekly-contest-183/problems/longest-happy-string/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    vector<int> maxNum;
public:
    bool compare(int x, int y) {
        return maxNum[x] > maxNum[y];
    }
    string longestDiverseString(int a, int b, int c) {
        maxNum = { a, b, c };
        vector<int> order = { 0, 1, 2 };
        sort(order.begin(), order.end(), compare);
        if (maxNum[order[1]] + maxNum[order[2]] >= (maxNum[order[0]] - 1) / 2) {
            int cnt1 = min(maxNum[order[0]] - 1 / 2, maxNum[order[1]]);
            int cnt2 = max(maxNum[order[0]] - 1 / 2 - cnt1, 0);
        }
        else {
            string s = "";
            for (int i = 0; i < maxNum[order[1]]; ++i)
                s += string(2, 'a' + order[0]) + string(1, 'a' + order[1]);
            for (int i = 0; i < maxNum[order[2]]; ++i)
                s += string(2, 'a' + order[0]) + string(1, 'a' + order[2]);
            s += string(2, 'a' + order[0]);
            return s;
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
