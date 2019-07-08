// leetcode_905.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/sort-array-by-parity/
// Given an array A of non - negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
// You may return any answer array that satisfies this condition.

#include <iostream>
#include <vector>
#include <deque>
using namespace std;


class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		// v1: it's too slow...
		//vector<int> result(0);
		//int len = A.size();
		//for (int i = 0; i < len; i++) {
		//	if (A[i] % 2 == 0)
		//		result.insert(result.begin(), A[i]);
		//	else
		//		result.push_back(A[i]);
		//}
		//return result;

		// v2: now it's much faster
		//vector<int> even(0);
		//vector<int> odd(0);
		//int len = A.size();
		//for (int i = 0; i < len; i++) {
		//	if (A[i] % 2 == 0)
		//		even.push_back(A[i]);
		//	else
		//		odd.push_back(A[i]);
		//}
		//even.insert(even.end(), odd.begin(), odd.end());
		//return even;

		// v3: slower than v2...
		//vector<int> arr(5001, 0);
		//int len = A.size();
		//for (int i = 0; i < len; i++)
		//	arr[A[i]] += 1;
		//vector<int> result(0);
		//for (int i = 0; i < 5001; i+=2)
		//	if (arr[i] >= 1)
		//		for (int j = 0; j < arr[i]; j++)
		//			result.push_back(i);
		//for (int i = 1; i < 5001; i += 2)
		//	if (arr[i] >= 1)
		//		for (int j = 0; j < arr[i]; j++)
		//			result.push_back(i);
		//return result;

		// v4: the speed is similar to v2
		deque<int> deq(0);
		int len = A.size();
		for (int i = 0; i < len; ++i) {
			if (A[i] % 2 == 0)
				deq.push_front(A[i]);
			else
				deq.push_back(A[i]);
		}
		return vector<int>(deq.begin(), deq.end());
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

