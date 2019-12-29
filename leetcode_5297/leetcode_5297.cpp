// leetcode_5297.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-169/problems/jump-game-iii/
/*
Given an array of non-negative integers arr, 
you are initially positioned at start index of the array. 
When you are at index i, you can jump to i + arr[i] or i - arr[i], 
check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation:
All possible ways to reach at index 3 with value 0 are:
index 5 -> index 4 -> index 1 -> index 3
index 5 -> index 6 -> index 4 -> index 1 -> index 3

Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true
Explanation:
One possible way to reach at index 3 with value 0 is:
index 0 -> index 4 -> index 1 -> index 3

Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.

Constraints:

1 <= arr.length <= 5 * 10^4
0 <= arr[i] < arr.length
0 <= start < arr.length
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> inQueue(n, false);
        queue<int> q;
        q.push(start);
        inQueue[start] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (arr[cur] == 0)
                return true;
            int j = cur - arr[cur];
            if (j >= 0 && j < n && !inQueue[j]) {
                inQueue[j] = true;
                q.push(j);
            }
            j = cur + arr[cur];
            if (j >= 0 && j < n && !inQueue[j]) {
                inQueue[j] = true;
                q.push(j);
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = { 4,2,3,0,3,1,2 };
    int start = 0;
    cout << sol.canReach(arr, start) << endl;
}
