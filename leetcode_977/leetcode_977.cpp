// leetcode_977.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/squares-of-a-sorted-array/
// Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
		// v1: not fast enough
		//int len = A.size();
		//for (int i = 0; i < len; ++i)
		//	A[i] *= A[i];
		//sort(A.begin(), A.end());
		//return A;

		// v2: just a bit faster...
		//int len = A.size();
		//vector<int> B(10001, 0);
		//vector<int> result(len);
		//int tmp = 0;
		//int cnt = 0;
		//for (int i = 0; i < len; ++i) {
		//	tmp = (A[i] >= 0) ? A[i] : -A[i];
		//	B[tmp] += 1;
		//}
		//for (int i = 0; i < 10001; ++i)
		//	for (int j = 0; j < B[i]; ++j) {
		//		result[cnt] = i * i;
		//		cnt++;
		//	}
		//return result;

		// v3: faster than 95%!!! Awesome!!!
		int len = A.size();
		int first_pos_idx = len;
		for (int i = 0; i < len; ++i) {
			if (A[i] >= 0) {
				first_pos_idx = i;
				break;
			}
		}
		vector<int> result(0);
		int pos_idx = first_pos_idx;
		int neg_idx = first_pos_idx - 1;
		int pos_v = 0;
		int neg_v = 0;
		while (pos_idx < len || neg_idx >= 0) {
			if (pos_idx >= len) {
				neg_v = A[neg_idx] * A[neg_idx];
				result.push_back(neg_v);
				neg_idx--;
			}
			else if (neg_idx < 0) {
				pos_v = A[pos_idx] * A[pos_idx];
				result.push_back(pos_v);
				pos_idx++;
			}
			else {
				pos_v = A[pos_idx] * A[pos_idx];
				neg_v = A[neg_idx] * A[neg_idx];
				if (pos_v <= neg_v) {
					result.push_back(pos_v);
					pos_idx++;
				}
				else {
					result.push_back(neg_v);
					neg_idx--;
				}
			}
		}
		return result;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

