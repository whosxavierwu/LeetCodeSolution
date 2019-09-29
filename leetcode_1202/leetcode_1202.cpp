// leetcode_1202.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-155/problems/smallest-string-with-swaps/
/*
You are given a string s, 
and an array of pairs of indices in the string pairs where pairs[i] = [a, b] 
indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.
Return the lexicographically smallest string that s can be changed to after using the swaps.

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination:
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination:
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination:
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
	int find(vector<int>& groupOf, int i) {
		if (groupOf[i] < 0) 
			return i;
		else {
			groupOf[i] = find(groupOf, groupOf[i]);
			return groupOf[i];
		}
	}
	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
		int len = s.length();
		vector<int> groupOf(len, -1);
		vector<vector<int>> m(len);
		for (vector<int>& pair : pairs) {
			int i = find(groupOf, pair[0]);
			int j = find(groupOf, pair[1]);
			if (i != j)
				groupOf[j] = i;
		}

		for (int i = 0; i < len; ++i)
			m[find(groupOf, i)].push_back(i);
		
		for (auto ids : m) {
			string ss = "";
			for (auto id : ids)
				ss += s[id];
			sort(begin(ss), end(ss));
			for (int i = 0; i < ids.size(); ++i)
				s[ids[i]] = ss[i];
		}
		return s;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}
