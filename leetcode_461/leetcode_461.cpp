// leetcode_461.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/hamming-distance/
// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

#include <iostream>

class Solution {
public:
	int hammingDistance(int x, int y) {
		// beats 100% ?!!!!!
		int z = x ^ y;
		int dist = 0;
		int tmp = 0; 
		while (z) {
			tmp = z >> 1;
			dist += z - (tmp << 1);
			z = tmp;
		}
		return dist;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
