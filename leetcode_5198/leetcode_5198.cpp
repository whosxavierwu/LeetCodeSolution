// leetcode_5198.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-155/problems/ugly-number-iii/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	unsigned long long gcd(unsigned long long a, unsigned long long b) {
		while (a != b) {
			if (a > b) 
				a = a - b;
			else
				b = b - a;
		}
		return a;
	}

	unsigned long long lcm(unsigned long long a, unsigned long long b) {
		return (a * b) / gcd(a, b);
	}

	int nthUglyNumber(int n, int a, int b, int c) {
		unsigned long long lcmAB = lcm(a, b);
		unsigned long long lcmAC = lcm(a, c);
		unsigned long long lcmBC = lcm(b, c);
		unsigned long long lcmABC = lcm(lcmAB, c);
		// Find the least integer k that satisfies the condition F(k) >= n
		int low = 1, high = 2 * (int)1e9;
		while (low < high) {
			int mid = low + (high - low) / 2;
			int cnt = mid / a + mid / b + mid / c - mid / lcmAB - mid / lcmAC - mid / lcmBC + mid / lcmABC;
			if (cnt < n)
				low = mid + 1;
			else
				high = mid;
		}
		return low;
	}
};

int main()
{
	Solution sol;
	cout << sol.nthUglyNumber(1000000000, 2, 217983653, 336916467) << endl;
}
