// leetcode_476.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/number-complement/
/*
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.

*/

#include <iostream>
using namespace std;

class Solution {
public:
	int findComplement(int num) {
		// v1: 4 ms, faster than 54.17% 
		int result = 0;
		int cnt = 0;
		while (num) {
			if (!(num & 1)) {
				result += (1 << cnt);
			}
			cnt++;
			num = num >> 1;
		}
		return result;
	}
};
int main()
{
	Solution sol;
	cout << sol.findComplement(5) << endl;
}
