// leetcode_5072.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxNumberOfApples(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		int count = 0;
		int sum = 0; 
		for (int a : arr) {
			sum += a;
			if (sum <= 5000)
				++count;
			else
				break;
		}
		return count;
	}
};

int main()
{
	Solution sol;
	vector<int> arr = { 900,950,800,1000,700,800 };
	cout << sol.maxNumberOfApples(arr) << endl;

}
