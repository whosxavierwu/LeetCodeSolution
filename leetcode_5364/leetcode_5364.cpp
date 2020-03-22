// leetcode_5364.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-181/problems/create-target-array-in-the-given-order/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> result;
        int actionNum = index.size();
        for (int actionIdx = 0; actionIdx < actionNum; ++actionIdx) {
            int idx = index[actionIdx];
            int value = nums[actionIdx];
            if (idx == result.size())
                result.push_back(value);
            else
                result.insert(result.begin() + idx, value);
        }
        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
