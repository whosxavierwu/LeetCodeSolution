// leetcode_239.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/sliding-window-maximum/

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // v2: faster than 87.57%, why???
        deque<int> dq;  // store idx instead of value
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() == i - k) 
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            // now dp.back() >= nums[i]
            dq.push_back(i);
            if (i >= k - 1) 
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
