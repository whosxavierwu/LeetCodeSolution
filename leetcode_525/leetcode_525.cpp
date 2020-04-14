// leetcode_525.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/contiguous-array/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int runSum = 0;
        unordered_map<int, int> mmap;
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            runSum += (nums[i] > 0 ? 1 : -1);
            if (runSum == 0)
                result = max(result, i + 1);
            auto iter = mmap.find(runSum);
            if (iter == mmap.end())
                mmap[runSum] = i;
            else  
                result = max(result, i - iter->second);
        }
        
        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
