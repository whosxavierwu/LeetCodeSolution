// leetcode_5197.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-155/problems/minimum-absolute-difference/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		int minGap = INT_MAX;
		for (int i = 1; i < arr.size(); ++i) {
			int gap = arr[i] - arr[i - 1];
			if (gap < minGap) minGap = gap;
		}
		vector<vector<int>> result;
		for (int i = 1; i < arr.size(); ++i) {
			int gap = arr[i] - arr[i - 1];
			if (gap == minGap)
				result.push_back({ arr[i - 1], arr[i] });
		}
		return result;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}
