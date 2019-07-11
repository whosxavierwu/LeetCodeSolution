// leetcode_922.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/sort-array-by-parity-ii/
//Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.
//Sort the array so that whenever A[i] is odd, i is odd;and whenever A[i] is even, i is even.
//You may return any answer array that satisfies this condition.
//2 <= A.length <= 20000
//A.length % 2 == 0
//0 <= A[i] <= 1000

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		// v1: too slow, beats 40%
		//vector<int> even(0);
		//vector<int> odd(0);
		//int len = A.size();
		//for (int i = 0; i < len; ++i)
		//	if (A[i] % 2 == 0)
		//		even.push_back(A[i]);
		//	else
		//		odd.push_back(A[i]);
		//vector<int> result(0);
		//for (int i = 0; i < len / 2; ++i) {
		//	result.push_back(even[i]);
		//	result.push_back(odd[i]);
		//}
		//return result;

		// v2: much better, beats 94.89%
		//vector<int> even(0);
		//vector<int> odd(0);
		//int len = A.size();
		//for (int i = 0; i < len; ++i)
		//	if (A[i] % 2 == 0)
		//		even.push_back(A[i]);
		//	else
		//		odd.push_back(A[i]);
		//vector<int> result(len);
		//int even_idx = 0, odd_idx = 0;
		//for (int i = 0; i < len; ++i) {
		//	if (i % 2 == 0) {
		//		result[i] = even[even_idx];
		//		even_idx++;
		//	}
		//	else {
		//		result[i] = odd[odd_idx];
		//		odd_idx++;
		//	}
		//}
		//return result;

		// v3: not as fast as v2, why? beats 81%
		//int len = A.size();
		//vector<int> even(len/2);
		//vector<int> odd(len/2);
		//vector<int> result(len);
		//int even_idx = 0, odd_idx = 0;
		//for (int i = 0; i < len; ++i)
		//	if (A[i] % 2 == 0) {
		//		even[even_idx] = A[i];
		//		even_idx++;
		//	}
		//	else {
		//		odd[odd_idx] = A[i];
		//		odd_idx++;
		//	}
		//
		//even_idx = 0, odd_idx = 0;
		//for (int i = 0; i < len; ++i) {
		//	if (i % 2 == 0) {
		//		result[i] = even[even_idx];
		//		even_idx++;
		//	}
		//	else {
		//		result[i] = odd[odd_idx];
		//		odd_idx++;
		//	}
		//}
		//return result;

		// v4: it's the slower !?? why??? beats 81.34%
		//int len = A.size();
		//vector<int> result(len,0);
		//int even_idx = 0, odd_idx = 1;
		//for (int i = 0; i < len; ++i)
		//	if (A[i] % 2 == 0) {
		//		result[even_idx] = A[i];
		//		even_idx += 2;
		//	}
		//	else {
		//		result[odd_idx] = A[i];
		//		odd_idx += 2;
		//	}
		//return result;

		// v5: faster than 94.89%
		// nums in i left should be even, nums in j left should be odd
		int j = 1;
		int len = A.size();
		for (int i = 0; i < len; i+=2) {
			if (A[i] % 2) {
				while (A[j])
					j += 2;
				int tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		}
		return A;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

