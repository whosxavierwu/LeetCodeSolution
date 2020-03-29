// leetcode_5369.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-182/problems/count-number-of-teams/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int len = rating.size();
        int result = 0;
        for (int i = 0; i < len; ++i) {
            int leftSmaller = 0;
            int leftBigger = 0;
            int rightSmaller = 0;
            int rightBigger = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (rating[j] < rating[i])
                    leftSmaller++;
                else
                    leftBigger++;
            }
            for (int j = i + 1; j < len; ++j) {
                if (rating[j] > rating[i])
                    rightBigger++;
                else
                    rightSmaller++;
            }
            result += leftSmaller * rightBigger + leftBigger * rightSmaller;
        }
        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
