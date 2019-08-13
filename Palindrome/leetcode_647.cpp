// leetcode_647.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/palindromic-substrings/
// The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
	int countSubstrings(string s) {
		int len = s.length();
		if (len <= 1)
			return 1;
		if (len == 2)
			return (s[0] == s[1]) ? 3 : 2;
		// v1: faster than 36.09%
		//int count = 0;
		//vector<vector<pair<int, int>>> results(len + 1);
		//int lenOfSub = 0;
		//lenOfSub = 1;
		//for (int i = 0; i < len; ++i)
		//	results[1].push_back({i, i});
		//count += len;
		//lenOfSub = 2;
		//for (int i = 1; i < len; ++i)
		//	if (s[i] == s[i - 1]) {
		//		results[2].push_back({ i - 1, i });
		//		++count;
		//	}	
		//for (lenOfSub = 3; lenOfSub <= len; ++lenOfSub) {
		//	for (pair<int, int> p : results[lenOfSub - 2]) {
		//		int left = p.first - 1;
		//		int right = p.second + 1;
		//		if (left < 0 || right >= len)
		//			continue;
		//		if (s[left] == s[right]) {
		//			results[lenOfSub].push_back({ left, right });
		//			++count;
		//		}
		//	}
		//}
		//return count;

		// v2: it's slower!!! why???
		//deque<pair<int, int>> deq;
		//int count = 0;
		//for (int i = 0; i < len; ++i)
		//	deq.push_back({i, i});
		//count += len;
		//for (int i = 1; i < len; ++i)
		//	if (s[i] == s[i - 1]) {
		//		deq.push_back({ i - 1, i });
		//		++count;
		//	}
		//while (!deq.empty()) {
		//	pair<int, int> p = deq.front();
		//	int left = p.first - 1;
		//	int right = p.second + 1;
		//	if (left >= 0 && right < len && s[left] == s[right]) {
		//		deq.push_back({ left, right });
		//		++count;
		//	}
		//	deq.pop_front();
		//}
		//return count;

		// v3: faster than 93.12%
		int count = 1;  // s[0]
		int left = 0, right = 0;
		for (int i = 1; i < len; ++i) {
			// <s[i]>
			++count;
			// s[i-1], s[i], s[i+1]
			for (left = i - 1, right = i + 1; left >= 0 && right < len; --left, ++right) {
				if (s[left] != s[right])
					break;
				++count;
			}
			// <s[i-1], s[i]>
			if (s[i - 1] == s[i]) {
				++count;
				for (left = i - 2, right = i + 1; left >= 0 && right < len; --left, ++right) {
					if (s[left] != s[right])
						break;
					++count;
				}
			}
		}
		return count;
	}
};
//
//int main()
//{
//	Solution sol; 
//	cout << sol.countSubstrings("abab") << endl;
//	return 0;
//}
//
