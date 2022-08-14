// leetcode_852.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/peak-index-in-a-mountain-array/
/*
Let's call an array arr a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
Given an integer array arr that is guaranteed to be a mountain, return any i such that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;
        while (start <= end) {
            if (start == end) {
                return start;
            }
            int mid = start + (end - start) / 2;
            bool higher_than_left = (mid == 0) || (arr[mid - 1] < arr[mid]);
            bool higher_than_right = (mid == arr.size()) || (arr[mid] > arr[mid + 1]);
            if (higher_than_left && higher_than_right) {
                return mid;
            } else if (higher_than_left && ~higher_than_right) {
                start = mid + 1;
            } else if (~higher_than_left && higher_than_right) {
                end = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
