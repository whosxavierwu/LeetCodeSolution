// leetcode_cn_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode-cn.com/contest/season/2019-fall/problems/deep-dark-fraction/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int gcd(int a, int b) {
		while (a != b) {
			if (a > b) 
				a = a - b;
			else
				b = b - a;
		}
		return a;
	}
	vector<int> fraction(vector<int>& cont) {
		int N = cont.size();
		vector<int> b = { cont[N - 1], 1 };
		for (int i = N - 2; i >= 0; --i) {
			int aa = b[0] * cont[i] + b[1];
			int bb = b[0];
			int gcd1 = gcd(aa, bb);
			b[0] = aa / gcd1;
			b[1] = bb / gcd1;
		}
		return b;
	}
};
int main()
{
	Solution sol;
	vector<int> cont = { 3, 2, 0, 2 };
	vector<int> result = sol.fraction(cont);
	cout << result[0] << " " << result[1] << endl;
}
