// leetcode_242.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/valid-anagram/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		// v1: faster than 21.47%
		//sort(s.begin(), s.end());
		//sort(t.begin(), t.end());
		//return (s == t);

		// v2 faster than 82.84%, less than 80.43%
		//vector<int> cnt1(26, 0);
		//vector<int> cnt2(26, 0);
		//for (char& w : s)
		//	cnt1[w - 'a'] += 1;
		//for (char& w : t)
		//	cnt2[w - 'a'] += 1;
		//for (int i = 0; i < 26; ++i)
		//	if (cnt1[i] != cnt2[i])
		//		return false;
		//return true;

		// v3 faster than 97.98%  , less than 63.00% , why???
		vector<int> cnt(26, 0);
		for (char& w : s)
			cnt[w - 'a'] += 1;
		for (char& w : t) {
			cnt[w - 'a'] -= 1;
			if (cnt[w - 'a'] < 0) return false;
		}
		for (int i = 0; i < 26; ++i)
			if (cnt[i] != 0)
				return false;
		return true;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}
