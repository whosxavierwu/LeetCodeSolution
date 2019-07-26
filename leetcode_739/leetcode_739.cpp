// leetcode_739.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/daily-temperatures

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		//// v1: faster than 57.60%
		//vector<int> nextGreaterIdxOf;
		//// save the indices of elements that need to find next greater element.
		//// we push it from 0 to len-1, so it's ascending
		//stack<int> idxHavingNoNextGreater;
		//int len = T.size();
		//for (int curIdx = 0; curIdx < len; ++curIdx) {
		//	// nextGreaterIdxOf stores the result of T[:curIdx]
		//	// now we add a new num, and need to refresh previous values
		//	// all we need to deal with, are the values that dont have next greater so far
		//	// we want to check if cur value is their greater value
		//	while ((!idxHavingNoNextGreater.empty()) 
		//		&& (T[nextGreaterIdxOf[idxHavingNoNextGreater.top()]] < T[curIdx])) {
		//		// T[result[uncheckedIdx.top()]] < T[curIdx])
		//		// means we the result of uncheckedIdx.top should be refreshed
		//		nextGreaterIdxOf[idxHavingNoNextGreater.top()] = curIdx;  // modify
		//		idxHavingNoNextGreater.pop();
		//	}
		//	// of course curIdx has no next greater so far
		//	idxHavingNoNextGreater.push(curIdx);
		//	// we set the next greater of curIdx to be itself
		//	nextGreaterIdxOf.push_back(curIdx);
		//}	
		//while (!idxHavingNoNextGreater.empty()) { 
		//	nextGreaterIdxOf[idxHavingNoNextGreater.top()] = 0;
		//	idxHavingNoNextGreater.pop();
		//}
		//// modify to the difference of idx
		//for (int i = 0; i < len; ++i)
		//	if (nextGreaterIdxOf[i] > 0)
		//		nextGreaterIdxOf[i] -= i;
		//return nextGreaterIdxOf;

		// v2 faster than 39.79% 
		vector<int> distToNextGreater(T.size(), 0);
		// save the indices of elements that need to find next greater element.
		stack<int> idxHavingNoNextGreater;
		for (int curIdx = 0; curIdx < T.size(); ++curIdx) {
			// distToNextGreater stores the result of T[:curIdx]
			// now adding a new num, 
			// need to refresh the values that dont have next greater so far
			// we want to check if cur value is their greater value
			// note here, if cur value isnt greater than top, 
			// cur value cant greater than values below top
			while ((!idxHavingNoNextGreater.empty())
				&& (T[idxHavingNoNextGreater.top()] < T[curIdx])) {
				distToNextGreater[idxHavingNoNextGreater.top()] = curIdx - idxHavingNoNextGreater.top();
				idxHavingNoNextGreater.pop();
			}
			// of course curIdx has no next greater so far
			idxHavingNoNextGreater.push(curIdx);
		}
		return distToNextGreater;

		//// v3: faster than 77.52% 
		//vector<int> distToNextGreater(T.size());
		//stack<int> sta;
		//for (int i = T.size() - 1; i >= 0; --i) {
		//	while (!sta.empty() && T[i] >= T[sta.top()]) 
		//		sta.pop();
		//	distToNextGreater[i] = sta.empty() ? 0 : sta.top() - i;
		//	sta.push(i);
		//}
		//return distToNextGreater;
	}
};

int main()
{
	// find the first warmer day
	vector<int> sample_in = { 73, 74, 75, 71, 69, 72, 76, 73 };
	vector<int> sample_out = { 1, 1, 4, 2, 1, 1, 0, 0 };
	Solution sol;
	vector<int> testOut = sol.dailyTemperatures(sample_in);
	for (int n : testOut)
		cout << n << endl;
	return 0;
}
