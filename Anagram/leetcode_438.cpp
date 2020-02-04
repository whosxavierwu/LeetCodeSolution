// leetcode_438.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/find-all-anagrams-in-a-string/
/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only 
and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Input:
s: "cbaebabacd" p: "abc"
Output:
[0, 6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Input:
s: "abab" p: "ab"
Output:
[0, 1, 2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string p) {
		if (s.length() != p.length())
			return false;
		vector<int> vec(26);
		for (char ch : p)
			vec[ch - 'a']++;
		for (char ch : s) {
			vec[ch - 'a']--;
			if (vec[ch - 'a'] < 0)
				return false;
		}
		return true;
	}

	vector<int> findAnagrams(string s, string p) {
		// v1: 1812 ms, faster than 5.03%
		//int sLen = s.length(), pLen = p.length();
		//vector<int> result;
		//for (int i = 0; (i + pLen) <= sLen; ++i) {
		//	if (isAnagram(s.substr(i, pLen), p))
		//		result.push_back(i);
		//}
		//return result;

		// v2: 36 ms, faster than 56.68%
		// v3: 28 ms, faster than 94.19%
		int sLen = s.length(), pLen = p.length();
		if (sLen < pLen) return {};
		vector<int> results;
		vector<int> pVec(26);
		for (char ch : p)
			pVec[ch - 'a']++;
		int left = 0, right = 0, head = 0, len = 0; 
		int counter = pLen;
		while (right < sLen) {
			if (pVec[s[right] - 'a'] > 0)
				counter--;
			pVec[s[right] - 'a']--;
			right++;
			while (counter == 0) {
				if (right - left == pLen)
					results.push_back(left);
				pVec[s[left] - 'a']++;
				if (pVec[s[left] - 'a'] > 0) 
					counter++;
				left++;
			}
		}
		return results;
	}
};
int main()
{
	Solution sol;
	vector<int> result; 
	result = sol.findAnagrams("cbaebabacd", "abc");
	for (int a : result) cout << a << " ";
	cout << endl;

	result = sol.findAnagrams("abab", "ab");
	for (int a : result) cout << a << " ";
	cout << endl;

	return 0;
}
