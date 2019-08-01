// leetcode_48.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/rotate-image/
/*
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, 
which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		// v1: faster than 84.34% 
		int len = matrix.size();
		int left = 0, right = len - 1;
		for (; left <= right; ++left, --right) {
			for (int i = 0; i < right - left; ++i) {
				int tmp = matrix[left + i][left];
				// copy from bottom-row to left-col
				matrix[left + i][left] = matrix[right][left + i];  
				// copy from right-col to bottom-row
				matrix[right][left + i] = matrix[right - i][right];
				// copy from bottom-row to left-col
				matrix[right - i][right] = matrix[left][right - i];
				// copy from bottom-row to left-col
				matrix[left][right - i] = tmp;
			}
		}
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
