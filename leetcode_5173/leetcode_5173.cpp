// leetcode_5173.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Return the number of permutations of 1 to n so that prime numbers are at prime indices (1-indexed.)

(Recall that an integer is prime if and only if it is greater than 1, 
and cannot be written as a product of two positive integers both smaller than it.)

Since the answer may be large, return the answer modulo 10^9 + 7.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//bool isPrime(int n) {
	//	for (int i = 2; i < n; ++i)
	//		if (n % i == 0)
	//			return true;
	//	return false;
	//}
	unsigned long long fact(int n) {
		unsigned long long result = 1;
		for (int i = 2; i <= n; ++i)
			result = (result * i) % 1000000007;
		return result;
	}
	int numPrimeArrangements(int n) {
		if (n == 1) return 1;
		if (n == 2) return 1;
		// count num of prime and calculate
		vector<int> isPrime(n + 1, -1);
		for (int i = 2; i <= n; ++i) {
			if (isPrime[i] == -1) 
				isPrime[i] = 1;
			for (int j = 2; i * j <= n; ++j)
				isPrime[i * j] = 0;
		}
		int numOfPrime = 0;
		for (int i = 2; i <= n; ++i) {
			if (isPrime[i] > 0)
				numOfPrime += 1;
		}
			
		unsigned long long result = fact(numOfPrime) * fact(n - numOfPrime);
		result = result % 1000000007;
		return result;
	}
};
int main()
{
	Solution sol;
	cout << sol.numPrimeArrangements(100) << endl;
}
