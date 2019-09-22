// leetcode_5198.cpp : This file contains the 'main' function. Program execution begins and ends there.
// todo https://leetcode.com/contest/weekly-contest-155/problems/ugly-number-iii/

#include <iostream>
#include <vector>
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
		unsigned long long lcm1 = lcm(a, b);
		lcm1 = lcm(lcm1, c);
		cout << lcm1 << endl;
		unsigned long long count = lcm1 / a + lcm1 / b + lcm1 / c - lcm1 / lcm(a, b) - lcm1 / lcm(a, c) - lcm1 / lcm(b, c) + 1;
		cout << count << endl;
		//int result = (n / count) * lcm1;
		//result += nthUglyNumber(n % count, a, b, c);
		//return result;
		return count;
	}
};

int main()
{
	Solution sol;
	cout << sol.nthUglyNumber(1000000000, 2, 217983653, 336916467) << endl;
}
