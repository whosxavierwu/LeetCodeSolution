// leetcode_5127.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://leetcode.com/contest/biweekly-contest-15/problems/remove-covered-intervals/
/*
Given a list of intervals, remove all intervals that are covered by another interval in the list. 
Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.

After doing so, return the number of remaining intervals.

Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.

Constraints:

1 <= intervals.length <= 1000
0 <= intervals[i][0] < intervals[i][1] <= 10^5
intervals[i] != intervals[j] for all i != j
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) { return (a[0] < b[0]) || ((a[0] == b[0]) && (a[1] > b[1])) ; });
        vector<vector<int>> results; 
        int count = 0;
        for (vector<int>& interval : intervals) {
            if (results.empty()) {
                results.push_back(interval);
            }
            else if (results.back()[1] <= interval[0]) {
                count += results.size();
                results.clear();
                results.push_back(interval);
            }
            else {
                bool isCovered = false;
                for (vector<int>& tmp : results) {
                    if (tmp[0] <= interval[0] && interval[1] <= tmp[1]) {
                        isCovered = true;
                        break;
                    }
                }
                if (!isCovered)
                    results.push_back(interval);
            }
        }
        count += results.size();
        return count;
    }
};
int main()
{
    std::cout << "Hello World!\n";
}

