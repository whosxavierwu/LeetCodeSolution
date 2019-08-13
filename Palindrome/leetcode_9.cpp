// leetcode_9.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/palindrome-number/
// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward
// Coud you solve it without converting the integer to a string?

#include <iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		if (x < 10)
			return true;	
		if (x % 10 == 0)
			return false;

		// v1: faster than 66.24%
		//int a = x;
		//long b = 0;
		//while (a) {
		//	b = b * 10 + a % 10;
		//	a /= 10;
		//}
		//return x == b;

		// v2: faster than 98.92% 
		// the main difference with v1 is stop condition
		int revertedNumber = 0;
		while (x > revertedNumber) { 
			revertedNumber = revertedNumber * 10 + x % 10;
			x /= 10;
		}

		// When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
		// For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
		// since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
		return x == revertedNumber || x == revertedNumber / 10;
	}
};
//
//int main()
//{
//	Solution sol;
//	cout << sol.isPalindrome(2147483647) << endl;
//	cout << sol.isPalindrome(121) << endl;
//	cout << sol.isPalindrome(1000021) << endl;
//	cout << sol.isPalindrome(1221) << endl;
//	cout << sol.isPalindrome(1234567321) << endl;
//	return 0;
//}
