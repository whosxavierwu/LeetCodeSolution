// leetcode_728.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/self-dividing-numbers/
// A self - dividing number is a number that is divisible by every digit it contains.
// For example, 128 is a self - dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
// Also, a self - dividing number is not allowed to contain the digit zero.
// Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.
// The boundaries of each input argument are 1 <= left <= right <= 10000.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isSelfDividing(int n) {
		// get all digit 
		int a = n;
		int d = 0;
		while (a) {
			d = a % 10;
			if (d == 0 || n % d > 0)
				return false;
			a = a / 10;
		}
		return true;
	}
	vector<int> selfDividingNumbers(int left, int right) {
		// v1: beats 78%
		vector<int> result(0);
		for (int n = left; n <= right; ++n)
			if (isSelfDividing(n))
				result.push_back(n);
		return result;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

