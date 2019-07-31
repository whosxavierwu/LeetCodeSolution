// leetcode_1051.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/height-checker/
/* not a well defined problems */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int heightChecker(vector<int>& heights) {
		// v1: faster than 64.29%
		vector<int> v = heights;
		int count = 0;
		sort(v.begin(), v.end());
		for (int i = 0; i < heights.size(); i++) {
			if (heights[i] != v[i]) count++;
		}
		return count;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
