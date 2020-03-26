// leetcode_149.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/max-points-on-a-line/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*int maxPoints(vector<vector<int>>& points) {
        int result = 0;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            unordered_map<float, int> wCount;
            int same = 1;
            int maxCount = 0;
            for (int j = i + 1; j < n; ++j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
                    same++;
                else {
                    float w = INT_MAX;
                    if (points[i][0] != points[j][0])
                        w = float(points[i][1] - points[j][1]) / float(points[i][0] - points[j][0]);
                    wCount[w] += 1;
                    maxCount = max(maxCount, wCount[w]);
                }
            }
            result = max(result, maxCount + same);
        }
        return result;
    }*/

    int maxPoints(vector<vector<int>>& points) {
        if (points.empty()) { return 0; }
        if (points.size() == 1) { return 1; }

        int Max = 0;
        for (int i = 0; i < points.size(); i++) {
            int same = 1;
            unordered_map<double, int> wCount;
            int localmax = 0;
            for (int j = i + 1; j < points.size(); j++) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
                    same++;
                else {
                    double myslope = slope(points[i], points[j]);
                    wCount[myslope]++;
                    localmax = max(localmax, wCount[myslope]);
                }
            }
            Max = max(Max, localmax + same);
        }
        return Max;
    }
    double slope(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) { return INT_MAX; }
        if (a[1] == b[1]) { return 0; }
        return (1.0 * a[0] - 1.0 * b[0]) / (1.0 * a[1] - 1.0 * b[1]);
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> points = { {1, 1}, {2, 2}, {3, 3} };
    cout << sol.maxPoints(points) << endl;
}
