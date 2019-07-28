// leetcode_1137.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Solution {
public:
	int tribonacci(int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;
		if (n == 2) return 1;
		int prev = 1;
		int prevprev = 1;
		int prevprevprev = 0;
		int cur;
		for (int i = 3; i <= n; ++i) {
			cur = prev + prevprev + prevprevprev;
			prevprevprev = prevprev;
			prevprev = prev;
			prev = cur;
		}
		return cur;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
