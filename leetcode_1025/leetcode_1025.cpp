// leetcode_1025.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/divisor-game/

#include <iostream>
using namespace std;

class Solution {
public:
	bool divisorGame(int N) {
		// 1f, 2t, 3f, 4t, 5f, 6t, 7f, 8t, 9f, 
		// faster than 80.36% 
		return !(N % 2);
	}
};

int main()
{
	Solution sol;
	cout << sol.divisorGame(196) << endl;
    std::cout << "Hello World!\n";
}
