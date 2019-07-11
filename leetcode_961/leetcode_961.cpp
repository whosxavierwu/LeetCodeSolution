// leetcode_961.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
// In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.
// Return the element repeated N times.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int repeatedNTimes(vector<int>& A) {
		// v1: use majority-elements-ii,  faster than 89.68%
		//int len = A.size();
		//int vote1 = 0, vote2 = 0;
		//int candidate1 = 0, candidate2 = 1;  // two candidate must be different
		//for (int i = 0; i < len; ++i) {
		//	if (A[i] == candidate1)  // assentor of cand1
		//		vote1++;
		//	else if (A[i] == candidate2)  // assentor of cand2
		//		vote2++;
		//	// NOTE: cand2 isn't consider as a dissenter to cand1!!! 
		//	else if (vote1 == 0) {  //  dissenter to replace cand1
		//		candidate1 = A[i];
		//		vote1 = 1;
		//	}
		//	else if (vote2 == 0) {  // dissenter to replace cand2
		//		candidate2 = A[i];
		//		vote2 = 1;
		//	}
		//	else {  // dissenter but not enough to replace cand1 or cand2
		//		vote1--;
		//		vote2--;
		//	}
		//} 
		//return (vote1 > vote2) ? candidate1 : candidate2;

		// v2: not very faster... faster than 89.43% 
		//int len = A.size();
		//int vote = 0;
		//int key = 0;
		//// check if A[0] is the result
		//key = A[0];
		//for (int i = 1; i <= len / 2 + 1; ++i)
		//	if (A[i] == key)
		//		return key;
		//// if A[0] isn't the result, get rid of it, and use Boyer-Moore
		//vote = 0;
		//for (int i = 1; i < len; ++i) {
		//	if (vote == 0)
		//		key = A[i];
		//	vote += (A[i] == key) ? 1 : -1;
		//}
		//return key;

		// v3: search neighbour: similar to v2
		int len = A.size();
		for (int k = 1; k <= 3; ++k)
			for (int i = 0; i < len - k; ++i)
				if (A[i] == A[i + k])
					return A[i];
		return -1;
	}
};

int main()
{
	Solution sol;
	vector<int> s;
	int res = 0;
	s = { 2,1,2,5,3,2 };
	res = sol.repeatedNTimes(s);
	cout << res << endl;
	s = { 5,1,5,2,5,3,5,4 };
	res = sol.repeatedNTimes(s);
	cout << res << endl;
	return 0;
}

