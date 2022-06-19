// leetcode_49.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/group-anagrams/
/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

All inputs will be in lowercase.
The order of your output does not matter.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <deque>
#include <string>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		// v1: faster than 79.31%
		unordered_map<string, vector<string>> mmap;
		for (string str : strs) {
			string sortedStr = str;
			sort(sortedStr.begin(), sortedStr.end());
			if (mmap.find(sortedStr) == mmap.end()) {
				mmap[sortedStr] = { str };
			}
			else {
				mmap[sortedStr].push_back(str);
			}
		}
		vector<vector<string>> result;
		for (auto iter = mmap.begin(); iter != mmap.end(); ++iter)
			result.push_back(iter->second);
		return result;

		// v2 faster than 5.02%
		//vector<vector<string>> result;
		//for (string str : strs) {
		//	string sortedStr = str;
		//	sort(sortedStr.begin(), sortedStr.end());
		//	bool found = false;
		//	for (vector<string>& cur : result) {
		//		if (cur[0] == sortedStr) {
		//			cur.push_back(str);
		//			found = true;
		//			break;
		//		}
		//	}
		//	if (!found) {
		//		result.push_back({ sortedStr, str });
		//	}
		//}
		//for (vector<string>& cur : result) {
		//	cur.erase(cur.begin());
		//}
		//return result;

		// v3: faster than 5.02% 
		//vector<vector<string>> result;
		//vector<string> mark;
		//for (string str : strs) {
		//	string sortedStr = str;
		//	sort(sortedStr.begin(), sortedStr.end());
		//	bool found = false;
		//	for (int i = 0; i < mark.size(); ++i) {
		//		if (mark[i] == sortedStr) {
		//			result[i].push_back(str);
		//			found = true;
		//			break;
		//		}
		//	}
		//	if (!found) {
		//		mark.push_back(sortedStr);
		//		result.push_back({ str });
		//	}
		//}
		//return result;

		// v4 faster than 10.22% 
		//vector<vector<string>> result;
		//unordered_map<string, vector<string>> mmap;
		//for (string& str : strs) {
		//	vector<int> countLetter(26, 0);
		//	for (char& w : str)
		//		countLetter[w - 'a'] += 1;
		//	string vec = ""; 
		//	for (int cnt : countLetter)
		//		vec += to_string(cnt) + "#";
		//	if (mmap.find(vec) == mmap.end()) {
		//		mmap[vec] = { str };
		//	}
		//	else {
		//		mmap[vec].push_back(str);
		//	}
		//}
		//for (auto iter = mmap.begin(); iter != mmap.end(); ++iter)
		//	result.push_back(iter->second);
		//return result;

		// v5: faster than 91.30% 
		unordered_map<string, vector<string>> mmap;
		for (string str : strs) {
			string sortedStr = str;
			sort(sortedStr.begin(), sortedStr.end());
			mmap[sortedStr].push_back(str);
		}
		vector<vector<string>> result;
		for (auto iter = mmap.begin(); iter != mmap.end(); ++iter)
			result.push_back(iter->second);
		return result;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}

