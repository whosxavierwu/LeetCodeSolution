// leetcode_1122.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/relative-sort-array/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		// len(arr2) <= len(arr1)
		// v1: faster than 90.92%
		map<int, int> cntMap;
		for (int a : arr1) {
			if (cntMap.find(a) == cntMap.end())
				cntMap[a] = 1;
			else
				cntMap[a] = cntMap[a] + 1;
		}
		vector<int> result;
		for (int a : arr2) {
			for (int i = 0; i < cntMap[a]; ++i)
				result.push_back(a);
			cntMap.erase(a);
		}
		for (map<int, int>::iterator iter = cntMap.begin(); iter != cntMap.end(); ++iter) {
			for (int i = 0; i < iter->second; ++i)
				result.push_back(iter->first);
		}
		return result;

		// v2: faster than 8.52%
		map<int, int> cntMap;
		for (int a : arr1) {
			if (cntMap.find(a) == cntMap.end())
				cntMap[a] = 1;
			else
				cntMap[a] = cntMap[a] + 1;
		}
		vector<int> result(arr1.size());
		int idx = 0;
		for (int a : arr2) {
			for (int i = 0; i < cntMap[a]; ++i)
				result[idx++] = a;
			cntMap.erase(a);
		}
		for (map<int, int>::iterator iter = cntMap.begin(); iter != cntMap.end(); ++iter) {
			for (int i = 0; i < iter->second; ++i)
				result[idx++] = iter->first;
		}
		return result;
	}
};

int main()
{
	Solution sol;
	vector<int> arr1 = { 2,3,1,3,2,4,6,7,9,2,19 };
	vector<int> arr2 = { 2,1,4,3,9,6 };
	vector<int> arr = sol.relativeSortArray(arr1, arr2);
	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << endl;
	}
	return 0;
}
