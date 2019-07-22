// leetcode_338.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/counting-bits
// count bits of 1 for 0<=i<=num

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		//// v1: faster than 15.10% O(n*sizeof(int)) time, O(1) space
		//vector<int> result;
		//for (int i = 0; i <= num; ++i) {
		//	int x = i;
		//	int cnt = 0;
		//	while (x > 0) {
		//		cnt += (x > ((x >> 1) << 1)) ? 1: 0;
		//		x = x >> 1;
		//	}
		//	result.push_back(cnt);
		//}
		//return result;

		//// v2 faster than 92.67% 
		//vector<int> result = { 0, 1 };
		//for (int p = 1; (1 << p) <= num; ++p) {
		//	result.insert(result.end(), result.begin(), result.end());
		//	for (int i = (1 << p); i < (1 << (p + 1)); ++i)
		//		result[i] += 1;
		//}
		//result.resize(num + 1);
		//return result;

		// v3: faster than 92.67%
		if (num == 0) return { 0 };
		vector<int> result = { 0, 1 };
		int p = 1;
		for (int i = 2; i <= num; ++i) {
			if (i == (1 << (p + 1)))
				++p;
			result.push_back(result[i - (1 << p)] + 1);
		}
		return result;
	}
};

int main()
{
	Solution sol;
	vector<int> result = sol.countBits(17);
	for (int a : result)
		cout << a << endl;
	return 0;
}
