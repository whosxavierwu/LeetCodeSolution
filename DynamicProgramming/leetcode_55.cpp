// leetcode_55.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/jump-game/
/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // v1: TLE
        //int n = nums.size();
        //vector<bool> canReach(n, false);
        //canReach[0] = true;
        //for (int i = 0; i < n; ++i) {
        //    if (canReach[i]) {
        //        for (int j = 1; j <= nums[i]; ++j)
        //            canReach[i + j] = true;
        //    }
        //}
        //return canReach[n - 1];

        // v2: TLE
        //int n = nums.size();
        //vector<bool> visited(n, false);
        //stack<int> sta;
        //sta.push(0);
        //while (!sta.empty()) {
        //    int top = sta.top();
        //    if (top == n - 1) 
        //        return true;
        //    sta.pop();
        //    visited[top] = true;
        //    for (int i = 1; i <= nums[top] && (top + i) < n; ++i)
        //        if (!visited[top + i])
        //            sta.push(top + i);
        //}
        //return false;

        // v3: 12 ms, faster than 72.24%
        int n = nums.size();
        int maxIdx = 0;
        for (int i = 0; i < n; ++i) {
            if (i > maxIdx)
                return false;
            maxIdx = max(maxIdx, i + nums[i]);
        }
        return true;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
