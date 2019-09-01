// leetcode_766.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/toeplitz-matrix/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		// v1:  8 ms, faster than 96.29% 
		//int N = matrix.size();
		//int M = matrix[0].size();
		//for (int i = 0; i < N - 1; ++i) {
		//	for (int j = 0; j < M - 1; ++j) {
		//		if (matrix[i][j] != matrix[i + 1][j + 1])
		//			return false;
		//	}
		//}
		//return true;

		// v2: 12 ms, faster than 75.12%
		// What if the matrix is stored on disk, 
		// and the memory is limited such that 
		// you can only load at most one row of the matrix into the memory at once?
		vector<int> vec = matrix[0];
		int N = matrix.size();
		int M = matrix[0].size();
		for (int i = 1; i < N; ++i) {
			for (int j = M - 2; j >= 0; --j) {
				if (vec[j] != matrix[i][j + 1]) return false;
				vec[j + 1] = matrix[i][j + 1];
			}
			vec[0] = matrix[i][0];
		}
		return true;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}
