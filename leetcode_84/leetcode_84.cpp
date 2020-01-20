// leetcode_84.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/largest-rectangle-in-histogram/
/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram
Input: [2,1,5,6,2,3]
Output: 10
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // v1 12 ms, faster than 88.86%
        if (heights.empty()) return 0;
        int n = heights.size();
        vector<int> lowerAtLeft(n);
        vector<int> lowerAtRight(n);
        lowerAtRight[n - 1] = n;
        lowerAtLeft[0] = -1;
        for (int i = 1; i < n; ++i) {
            int left = i - 1;
            while (left >= 0 && heights[left] >= heights[i])
                left = lowerAtLeft[left];
            lowerAtLeft[i] = left;
        }
        for (int i = n - 2; i >= 0; --i) {
            int right = i + 1;
            while (right < n && heights[right] >= heights[i])
                right = lowerAtRight[right];
            lowerAtRight[i] = right;
        }
        int result = 0;
        for (int i = 0; i < n; ++i)
            result = max(result, (lowerAtRight[i] - lowerAtLeft[i] - 1) * heights[i]);
        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
