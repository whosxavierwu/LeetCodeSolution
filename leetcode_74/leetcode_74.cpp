// leetcode_74.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/search-a-2d-matrix/
/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		// v1: 8 ms, faster than 93.88% 
		int N = matrix.size();
		if (N == 0) return false;
		int M = matrix[0].size();
		int i = 0, j = M - 1;
		while (i < N && j >= 0) {
			if (matrix[i][j] == target) return true;
			else if (target < matrix[i][j]) --j;
			else ++i;
		}
		return false;

		// v2: 12 ms, faster than 50.80%
		//int N = matrix.size();
		//if (N == 0) return false;
		//int M = matrix[0].size();
		//int left = 0, right = N * M - 1;
		//while (left <= right) {
		//	int mid = (left + right) / 2;
		//	int i = mid / M;
		//	int j = mid % M;
		//	if (matrix[i][j] == target) return true;
		//	else if (target < matrix[i][j]) right = mid - 1;
		//	else left = mid + 1;
		//}
		//return false;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

