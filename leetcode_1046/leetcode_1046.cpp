// leetcode_1046.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/last-stone-weight/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (int stone : stones)
            q.push(stone);
        while (q.size() >= 2) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            if (a > b)
                q.push(a - b);
        }
        return q.empty() ? 0 : q.top();
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
