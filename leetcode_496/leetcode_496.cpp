// leetcode_496.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		// v1: faster than 98.11% 
		stack<int> idxHavingNoNextGreater;
		map<int, int> map1;
		for (int curIdx = 0; curIdx < nums2.size(); ++curIdx) {
			while ((!idxHavingNoNextGreater.empty())
				&& (nums2[idxHavingNoNextGreater.top()] < nums2[curIdx])) {
				map1[nums2[idxHavingNoNextGreater.top()]] = nums2[curIdx];
				idxHavingNoNextGreater.pop();
			}
			idxHavingNoNextGreater.push(curIdx);
		}
		vector<int> result;
		for (int a : nums1) {
			auto tmp = map1.find(a);
			if (tmp != map1.end())
				result.push_back(map1[a]);
			else
				result.push_back(-1);
		}
		return result;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

