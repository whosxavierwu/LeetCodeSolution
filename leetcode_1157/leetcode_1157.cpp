// leetcode_1157.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/online-majority-element-in-subarray/
/*
Implementing the class MajorityChecker, which has the following API:

MajorityChecker(int[] arr) constructs an instance of MajorityChecker with the given array arr;
int query(int left, int right, int threshold) has arguments such that:
0 <= left <= right < arr.length representing a subarray of arr;
2 * threshold > right - left + 1, ie. the threshold is always a strict majority of the length of the subarray
Each query(...) returns the element in arr[left], arr[left+1], ..., arr[right] that occurs at least threshold times, or -1 if no such element exists.

*/
#include <iostream>
#include <vector>
using namespace std;

class MajorityChecker {
public:
	MajorityChecker(vector<int>& arr) {

	}

	int query(int left, int right, int threshold) {

	}
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
int main()
{
    std::cout << "Hello World!\n";
}
