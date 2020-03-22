// leetcode_5349.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/biweekly-contest-22/problems/cinema-seat-allocation/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int prevRow = 0;
        vector<bool> reserved(11, false);
        int count = 0;
        int calculatedRow = 0;
        for (vector<int> seat : reservedSeats) {
            if (seat[0] > prevRow) {
                if (seat[0] - prevRow > 1)
                    count += 2 * (seat[0] - prevRow - 1);
                if (prevRow != 0) {
                    // 2345, 4567, 6789
                    bool a = !(reserved[2] | reserved[3]);
                    bool b = !(reserved[4] | reserved[5]);
                    bool c = !(reserved[6] | reserved[7]);
                    bool d = !(reserved[8] | reserved[9]);
                    count += max(b & c, (a & b) + (c & d));
                    reserved.assign(11, false);
                }
            }
            reserved[seat[1]] = true;
            prevRow = seat[0];
        }
        if (n > prevRow)
            count += 2 * (n - prevRow);
        if (prevRow != 0) {
            // 2345, 4567, 6789
            bool a = !(reserved[2] | reserved[3]);
            bool b = !(reserved[4] | reserved[5]);
            bool c = !(reserved[6] | reserved[7]);
            bool d = !(reserved[8] | reserved[9]);
            count += max(b & c, (a & b) + (c & d));
            reserved.assign(11, false);
        }
        return count;
    }
};

int main()
{
    Solution sol;
    //int n = 3;
    //vector<vector<int>> reservedSeats = { {1,2} ,{1,3},{1,8},{2,6},{3,1},{3,10} };
    int n = 4;
    vector<vector<int>> reservedSeats = { {4,3}, {1,4}, {4,6},{1,7} };
    //vector<vector<int>> reservedSeats = {  {1,4},{1,7}, {4,3},{4,6} };
    cout << sol.maxNumberOfFamilies(n, reservedSeats) << endl;
}
