// leetcode_5280.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-166/problems/group-the-people-given-the-group-size-they-belong-to/
/*
There are n people whose IDs go from 0 to n - 1 and each person belongs exactly to one group. 
Given the array groupSizes of length n telling the group size each person belongs to, 
return the groups there are and the people's IDs each group includes.

You can return any solution in any order and the same applies for IDs. 
Also, it is guaranteed that there exists at least one solution.

Example 1:

Input: groupSizes = [3,3,3,3,3,1,3]
Output: [[5],[0,1,2],[3,4,6]]
Explanation:
Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].
Example 2:

Input: groupSizes = [2,1,3,3,3,2]
Output: [[1],[0,5],[2,3,4]]


Constraints:

groupSizes.length == n
1 <= n <= 500
1 <= groupSizes[i] <= n
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> pepolesWithGroupSizeOf(n + 1); 
        for (int i = 0; i < n; ++i)
            pepolesWithGroupSizeOf[groupSizes[i]].push_back(i);
        vector<vector<int>> groups; 
        for (int curGroupSize = 1; curGroupSize <= n; ++curGroupSize) {
            if (!pepolesWithGroupSizeOf[curGroupSize].empty()) {
                int curNumOfGroup = pepolesWithGroupSizeOf[curGroupSize].size() / curGroupSize;
                for (int i = 0; i < curNumOfGroup; ++i) {
                    vector<int> tmp(pepolesWithGroupSizeOf[curGroupSize].begin() + i * curGroupSize, pepolesWithGroupSizeOf[curGroupSize].begin() + (i + 1) * curGroupSize);
                    groups.push_back(tmp);
                }
            }
        }
        return groups;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
