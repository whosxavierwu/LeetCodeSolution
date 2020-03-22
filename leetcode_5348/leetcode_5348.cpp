// leetcode_5348.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  https://leetcode.com/contest/biweekly-contest-22/problems/find-the-distance-value-between-two-arrays/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // |x-y|<=d    -d <= x-y <= d    y-d <= x <= y+d
        sort(arr2.begin(), arr2.end());
        vector<pair<int, int>> intervals;
        for (int a : arr2) {
            if (intervals.empty())
                intervals.push_back({ a - d, a + d });
            else if (intervals.back().second >= (a - d))
                intervals.back().second = a + d;
            else
                intervals.push_back({ a - d, a + d });
        }
        int count = 0;
        for (int a : arr1) {
            bool isGood = true;
            for (pair<int, int> interval : intervals)
                if (a >= interval.first && a <= interval.second) {
                    isGood = false;
                    break;
                }
                else if (a < interval.first) {
                    isGood = false;
                    count++;
                    break;
                }
            if (isGood)
                count++;
        }
        return count;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
