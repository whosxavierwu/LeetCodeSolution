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
		vector<pair<int, int>> vec(26, { 0,0 });  // first: length of longest sustring, total occurance
		char prev = ' ';
		int substrCnt = 0;
		for (char& c : text) {
			if (c != prev && prev != ' ') {
				vec[prev - 'a'].first = max(vec[prev - 'a'].first, substrCnt);
				substrCnt = 0;
			}
			substrCnt += 1;
			vec[c - 'a'].second += 1;
			prev = c;
		}
		int result = 0;
		for (int i = 0; i < 26; ++i) {
			result = max(result, vec[i].first + (vec[i].second > vec[i].first));
		}
		return result;
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
