// leetcode_5069.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Given a string s, return the last substring of s in lexicographical order.

Example 1:

Input: "abab"
Output: "bab"
Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba", "bab"]. The lexicographically maximum substring is "bab".
Example 2:

Input: "leetcode"
Output: "tcode"

*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

// v1: todo how does it work? it takes 590+ms! this is the solution of the winner
class Solution {
public:
	string lastSubstring(string s) {
		int n = s.size();
		string _s = s + '$';  // why?
		vector<int> idxSorted(n + 1);  // containing the index
		// sort indices in lexicographical order
		for (int i = 0; i <= n; ++i) idxSorted[i] = i;
		sort(idxSorted.begin(), idxSorted.end(),
			[&](int a, int b) {
				if (_s[a] == _s[b]) return a > b;
				return _s[a] < _s[b];
			});

		vector<int> c(n + 1, 0), r(n + 1), cnt(n + 1);
		for (int i = 0; i <= n; i++) r[i] = _s[i];  // char to int ?
		for (int len = 1; len <= n; len *= 2) {  // ?
			for (int i = 0; i <= n; i++) {
				c[idxSorted[i]] = i;
				// ?
				if (i > 0
					&& r[idxSorted[i - 1]] == r[idxSorted[i]]
					&& idxSorted[i - 1] + len <= n
					&& r[idxSorted[i - 1] + len / 2] == r[idxSorted[i] + len / 2])
					c[idxSorted[i]] = c[idxSorted[i - 1]];
			}
			for (int i = 0; i <= n; ++i) {
				cnt[i] = i;
				r[i] = idxSorted[i];
			}
			for (int i = 0; i <= n; ++i) {
				int s1 = r[i] - len;
				if (s1 >= 0) {
					idxSorted[cnt[c[s1]]] = s1;
					cnt[c[s1]]++;
				}
			}
			c.swap(r);
		}

		return s.substr(idxSorted[s.size()]);
	}
};

//v2: brute-force  32ms  faster than 25.00%
class Solution {
public:
	string lastSubstring(string s) {
		int i = 0;
		for (int j = 1; j < s.size(); ++j) {
			int sz = 0;
			for (; j + sz < s.size(); ++sz) {
				if (s[i + sz] == s[j + sz]) continue;
				if (s[j + sz] > s[i + sz]) i = j;
				break;
			}
			if (j + sz == s.size()) break;
		}
		return s.substr(i);
	}
};

//v3: 32ms
class Solution {
public:
	string lastSubstring(string s) {
		int n = s.size();
		vector<int> pre(n, 0);
		int start = 0;
		int to_match = 0;
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] > s[start]) {
				start = i;
				to_match = start;
			}
			else if (s[to_match] == s[i]) {
				if (i - start <= 2 * (to_match - start)) {
					pre[to_match] = to_match - start;
					start = to_match;
					to_match = start + 1;
				}
				else {
					to_match++;
				}
			}
			else if (s[to_match] > s[i]) {
				to_match = start;
			}
			else if (s[to_match] < s[i]) {
				start = i - (to_match - start);
				to_match = start;
			}
		}
		int tot = 0;
		int pos = start;
		while (pos > 0) {
			tot += pre[pos];
			pos -= pre[pos];
			if (pre[pos] == 0) break;
		}
		return s.substr(start - tot);
	}
};


int main()
{
	Solution sol;
	string s;
	s = "abab";
	cout << sol.lastSubstring(s) << endl;
	s = "leetcode";
	cout << sol.lastSubstring(s) << endl;
	s = "xbylisvborylklftlkcioajuxwdhahdgezvyjbgaznzayfwsaumeccpfwamfzmkinezzwobllyxktqeibfoupcpptncggrdqbkji";
	cout << sol.lastSubstring(s) << endl;
}
