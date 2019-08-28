// leetcode_763.cpp : This file contains the 'main' function. Program execution begins and ends there.
// todo https://leetcode.com/problems/partition-labels/
/*
A string S of lowercase letters is given. 
We want to partition this string into as many parts as possible 
so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

Note:
S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> partitionLabels(string S) {
		// v1: 12 ms, faster than 17.67%, 10 MB, less than 6.45%
		//unordered_map<char, vector<int>> mmap;
		//int len = S.length();
		//for (int i = 0; i < len; ++i) {
		//	mmap[S[i]].push_back(i);
		//}
		//vector<int> result;
		//int curMaxIdx = -1;
		//int prev = 0;
		//for (int i = 0; i < len; ++i) {
		//	curMaxIdx = max(curMaxIdx, mmap[S[i]].back());
		//	if (i == curMaxIdx) {
		//		result.push_back(i - prev + 1);
		//		curMaxIdx = -1;
		//		prev = i + 1;
		//	}
		//}
		//return result;

		// v2: 4 ms, faster than 91.79%,  8.7 MB, less than 80.65% 
		vector<int> vec(26, -1);
		int len = S.length();
		for (int i = 0; i < len; ++i)
			vec[S[i] - 'a'] = i;
		vector<int> result;
		int curMaxIdx = -1;
		int prev = 0;
		for (int i = 0; i < len; ++i) {
			curMaxIdx = max(curMaxIdx, vec[S[i] - 'a']);
			if (i == curMaxIdx) {
				result.push_back(i - prev + 1);
				curMaxIdx = -1;
				prev = i + 1;
			}
		}
		return result;
	}
};
int main()
{
	Solution sol;
	vector<int> vec = sol.partitionLabels("ababcbacadefegdehijhklij");
	//vector<int> vec = sol.partitionLabels("caedbdedda");
	for (int a : vec)
		cout << a << endl;
}
