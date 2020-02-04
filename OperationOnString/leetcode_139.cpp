// leetcode_139.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/word-break/
/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
			 Note that you are allowed to reuse a dictionary word.

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		//// https://leetcode.com/problems/word-break/discuss/43814/C%2B%2B-Dynamic-Programming-simple-and-fast-solution-(4ms)-with-optimization
		//// v1: 8 ms, faster than 76.42% 
		//if (wordDict.empty()) return false;
		//unordered_set<string> wordSet;
		//for (string word : wordDict)
		//	wordSet.insert(word);
		//vector<bool> isGoodString(s.length() + 1, false);
		//isGoodString[0] = true;
		//// goodString+word=goodString
		//for (int i = 1; i <= s.length(); ++i) {
		//	for (int j = i - 1; j >= 0; --j) {
		//		if (isGoodString[j]) {
		//			string word = s.substr(j, i - j);
		//			if (wordSet.find(word) != wordSet.end()) {
		//				isGoodString[i] = true;
		//				break;
		//			}
		//		}
		//	}
		//}
		//return isGoodString[s.length()];

		// v2: 4 ms, faster than 94.79%
		if (wordDict.empty()) return false;
		int maxWordLen = 0;
		unordered_set<string> wordSet;
		for (string word: wordDict){
			wordSet.insert(word);
			if (word.length() > maxWordLen)
				maxWordLen = word.length();
		}
		vector<bool> isGoodString(s.length() + 1, false);
		isGoodString[0] = true;
		for (int i = 1; i <= s.length(); ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (i - j > maxWordLen)
					break;
				if (isGoodString[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
					isGoodString[i] = true;
					break;
				}
			}
		}
		return isGoodString[s.length()];
	}
};
int main()
{
    std::cout << "Hello World!\n";
}
