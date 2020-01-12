// leetcode_5309.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-171/problems/number-of-operations-to-make-network-connected/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int par[100005];
public:
    int find(int a) {
        return par[a] == a ? a : par[a] = find(par[a]);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;
        int result = n - 1;
        for (int i = 0; i < n; ++i)
            par[i] = i;
        for (vector<int>& connection : connections) {
            int ta = find(connection[0]);
            int tb = find(connection[1]);
            if (ta != tb) {
                result--;
                par[ta] = tb;
            }
        }
        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
