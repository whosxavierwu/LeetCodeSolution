// leetcode_240.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/search-a-2d-matrix-ii/
/*
Write an efficient algorithm that searches for a value in an m x n matrix. 

This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Consider the following matrix:
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.
Given target = 20, return false.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	// v1: 152 ms, faster than 20.51%
	//bool searchMatrix(vector<vector<int>>& matrix, int target) {
	//	int N = matrix.size();
	//	if (N == 0) return false;
	//	int M = matrix[0].size();
	//	if (M == 0) return false;
	//	for (int i = 0; i < N; ++i) {
	//		if (target < matrix[i].front()) return false;
	//		if (target > matrix[i].back()) continue;
	//		int left = 0, right = M - 1;
	//		while (left <= right) {
	//			int mid = left + (right - left) / 2;
	//			if (target == matrix[i][mid]) return true;
	//			else if (target < matrix[i][mid]) right = mid - 1;
	//			else left = mid + 1;
	//		}
	//	}
	//	return false;
	//}

	// v2: 216 ms, faster than 15.09%, it's worse!! why??? 
	//bool func(const vector<vector<int>>& matrix, int target, 
	//	pair<int, int> p1, pair<int, int> p2) {
	//	if (target < matrix[p1.first][p1.second] || matrix[p2.first][p2.second] < target)
	//		return false;
	//	// same row or same column
	//	if (p1.first == p2.first || p1.second == p2.second) {  
	//		int left = (p1.first == p2.first) ? p1.second: p1.first;
	//		int right = (p1.first == p2.first) ? p2.second: p2.first;
	//		while (left <= right) {
	//			int mid = (left + right) / 2;
	//			int cur = (p1.first == p2.first) ? matrix[p1.first][mid] : matrix[mid][p1.second];
	//			if (target == cur) return true;
	//			else if (target < cur) right = mid - 1;
	//			else left = mid + 1;
	//		}
	//		return false;
	//	}
	//	// target is not in (0,0)~(k,k) or (k+1,k+1)~()
	//	int K = min(p2.first - p1.first, p2.second - p1.second);
	//	int n = -1; 
	//	for (int k = 0; k <= K; ++k) {
	//		int cur = matrix[p1.first + k][p1.second + k];
	//		if (target == cur) return true;
	//		else if (cur < target) n = k;
	//		else break;
	//	}
	//	bool result = false;
	//	// up right
	//	if (p1.second + n + 1 <= p2.second)
	//		result = func(matrix, target, {p1.first, p1.second + n + 1}, {p1.first + n, p2.second});
	//	if (result) return true;
	//	// down left
	//	if (p1.first + n + 1 <= p2.first)
	//		result = func(matrix, target, {p1.first + n + 1, p1.second}, {p2.first, p1.second + n});
	//	return result;
	//}
	//bool searchMatrix(vector<vector<int>>& matrix, int target) {
	//	int N = matrix.size();
	//	if (N == 0) return false;
	//	int M = matrix[0].size();
	//	if (M == 0) return false;
	//	return func(matrix, target, { 0, 0 }, { N - 1, M - 1 });
	//}

	// v3: 64 ms, faster than 84.14%
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int N = matrix.size();
		if (N == 0) return false;
		int M = matrix[0].size();
		int i = 0, j = M - 1;  // start from the upright point why?
		while (i < N && j >= 0) {
			if (matrix[i][j] == target) return true;
			else if (matrix[i][j] > target) --j;
			else ++i;
		}
		return false;
	}
};

int main()
{
	Solution sol;
	//vector<vector<int>> mat = { {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30} };
	//vector<vector<int>> mat = { {1,4},{2,5} };
	//int target = 2;
	//vector<vector<int>> mat = { {1,3,5} };
	//vector<vector<int>> mat = { 
	//	{4,7,11,12,16,21,23,26},
	//	{5,12,17,17,18,23,26,31},
	//	{8,15,21,25,26,29,33,34},
	//	{13,20,26,26,29,34,39,40},
	//	{18,21,31,36,41,42,42,44},
	//	{19,23,31,39,46,49,50,53},
	//	{23,25,33,40,50,51,55,60},
	//	{27,28,33,44,51,56,61,65},
	//	{32,35,39,45,54,56,65,68},
	//	{33,38,40,49,56,57,66,71} 
	//};
	//int target = 51;
	vector<vector<int>> mat = { {1,3,5,7,9},{2,4,6,8,10},{11,13,15,17,19},{12,14,16,18,20},{21,22,23,24,25} };
	int target = 13;
	cout << sol.searchMatrix(mat, target) << endl;
}
