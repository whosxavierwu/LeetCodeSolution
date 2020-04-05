// leetcode_5361.cpp : This file contains the 'main' function. Program execution begins and ends there.
// todo https://leetcode.com/contest/biweekly-contest-23/problems/circle-and-rectangle-overlapping/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int dist_x1 = abs(x_center - x1);
        int dist_x2 = abs(x_center - x2);
        int dist_y1 = abs(y_center - y1);
        int dist_y2 = abs(y_center - y2);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

