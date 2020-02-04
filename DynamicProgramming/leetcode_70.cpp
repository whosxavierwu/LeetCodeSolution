// leetcode_70.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/climbing-stairs/
// one or two step

#include <iostream>

class Solution {
public:
	int climbStairs(int n) {
		// v1: faster than 59.22% 
		//if (n == 1) return 1;
		//if (n == 2) return 2;
		//int prev = 2;
		//int prevprev = 1;
		//int cur = 0;
		//for (int i = 3; i <= n; ++i) {
		//	cur = prev + prevprev;
		//	prevprev = prev;
		//	prev = cur;
		//}
		//return cur;

		// v2 TLE
		//if (n <= 2) return n;
		//return climbStairs(n - 1) + climbStairs(n - 2);

		// v3: faster than 100.00% 
		if (n <= 2) return n;
		int prev = 2;
		int prevprev = 1; 
		int cur = 0;
		for (int i = 3; i <= n; ++i) {
			cur = prev + prevprev;
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

