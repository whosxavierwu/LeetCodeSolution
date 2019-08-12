// leetcode_1156.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/swap-for-longest-repeated-character-substring/
/*
Given a string text, we are allowed to swap two of the characters in the string. 
Find the length of the longest substring with repeated characters.

Input: text = "ababa"
Output: 3
Explanation: We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. 
Then, the longest repeated character substring is "aaa", which its length is 3.

Input: text = "aaabaaa"
Output: 6
Explanation: Swap 'b' with the last 'a' (or the first 'a'), 
and we get longest repeated character substring "aaaaaa", which its length is 6.

Input: text = "aaabbaaa"
Output: 4

Input: text = "aaaaa"
Output: 5
Explanation: No need to swap, longest repeated character substring is "aaaaa", length is 5.

Input: text = "abcdef"
Output: 1

Constraints:
1 <= text.length <= 20000
text consist of lowercase English characters only.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxRepOpt1(string text) {
		// v1: faster than 97.51%, less than 100.00%
		vector<pair<char, int>> vec;  // first: char, second: count
		vector<int> totalCnt(26);
		char prev = ' ';
		int substrCnt = 0;
		for (char& c : text) {
			totalCnt[c - 'a'] += 1;
			if (c != prev && prev != ' ') {
				vec.push_back(make_pair(prev, substrCnt));
				substrCnt = 0;
			}
			substrCnt += 1;
			prev = c;
		}
		if (substrCnt > 0)
			vec.push_back(make_pair(prev, substrCnt));
		int maxSubLen = 0;
		for (int i = 0; i < vec.size(); ++i) {
			int curSubStrCnt = vec[i].second + 1;
			int tmp = curSubStrCnt;
			if (i >= 2 && vec[i - 1].second == 1 && vec[i - 2].first == vec[i].first)
				tmp = max(tmp, curSubStrCnt + vec[i - 2].second);
			if (i+2 < vec.size() && vec[i + 1].second == 1 && vec[i + 2].first == vec[i].first)
				tmp = max(tmp, curSubStrCnt + vec[i + 2].second);
			tmp = min(tmp, totalCnt[vec[i].first - 'a']);
			if (tmp > maxSubLen) maxSubLen = tmp;
		}
		return maxSubLen;
	}
};

int main()
{
	Solution sol;
	string text;
	text = "ababa";
	cout << sol.maxRepOpt1(text) << endl;
	text = "aaabaaa";
	cout << sol.maxRepOpt1(text) << endl;
	text = "aaabbaaa";
	cout << sol.maxRepOpt1(text) << endl;
	text = "aaaaa";
	cout << sol.maxRepOpt1(text) << endl;
	text = "abcdef";
	cout << sol.maxRepOpt1(text) << endl;
}
