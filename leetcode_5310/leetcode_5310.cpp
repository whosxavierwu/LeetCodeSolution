// leetcode_5310.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-171/problems/minimum-distance-to-type-a-word-using-two-fingers/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dist(int a, int b) {
        int ax = a / 6;
        int ay = a % 6;
        int bx = b / 6;
        int by = b % 6;
        return abs(ax - bx) + abs(ay - by);
    }

    int minimumDistance(string word) { 
        int dp[300][26][26];
        for (int i = 0; i < word.size(); ++i) {
            int t = word[i] - 'A';
            for (int j = 0; j < 26; ++j)
                for (int k = 0; k < 26; ++k)
                    dp[i + 1][j][k] = INT_MAX / 3;
            for (int j = 0; j < 26; ++j)
                for (int k = 0; k < 26; ++k) {
                    dp[i + 1][j][t] = min(dp[i + 1][j][t], dp[i][j][k] + dist(t, k));
                    dp[i + 1][t][k] = min(dp[i + 1][t][k], dp[i][j][k] + dist(j, t));
                }
        }
        int result = INT_MAX / 3;
        for (int j = 0; j < 26; ++j)
            for (int k = 0; k < 26; ++k) {
                result = min(result, dp[word.size()][j][k]);
            }
        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
