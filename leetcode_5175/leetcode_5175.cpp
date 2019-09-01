// leetcode_5175.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/can-make-palindrome-from-substring/
/*
Given a string s, we make queries on substrings of s.

For each query queries[i] = [left, right, k], we may rearrange the substring s[left], ..., s[right], 
and then choose up to k of them to replace with any lowercase English letter.

If the substring is possible to be a palindrome string after the operations above, the result of the query is true. 
Otherwise, the result is false.

Return an array answer[], where answer[i] is the result of the i-th query queries[i].

Note that: Each letter is counted individually for replacement so if for example s[left..right] = "aaa", and k = 2, we can only replace two of the letters.  (Also, note that the initial string s is never modified by any query.)

Example :

Input: s = "abcda", queries = [[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
Output: [true,false,false,true,true]
Explanation:
queries[0] : substring = "d", is palidrome.
queries[1] : substring = "bc", is not palidrome.
queries[2] : substring = "abcd", is not palidrome after replacing only 1 character.
queries[3] : substring = "abcd", could be changed to "abba" which is palidrome. Also this can be changed to "baab" first rearrange it "bacd" then replace "cd" with "ab".
queries[4] : substring = "abcda", could be changed to "abcba" which is palidrome.


Constraints:

1 <= s.length, queries.length <= 10^5
0 <= queries[i][0] <= queries[i][1] < s.length
0 <= queries[i][2] <= s.length
s only contains lowercase English letters.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
		// v1: 864 ms, faster than 16.67%
		vector<bool> result;
		vector<vector<int>> indicesOfLetter(26);
		int len = s.length();
		for (int i = 0; i < len; ++i)
			indicesOfLetter[s[i] - 'a'].push_back(i);
		for (vector<int> query : queries) {
			int left = query[0], right = query[1], k = query[2];
			int tmplen = right - left + 1;
			int numOfOddLetter = 0;
			for (int i = 0; i < 26; ++i) {
				int low = lower_bound(indicesOfLetter[i].begin(), indicesOfLetter[i].end(), left) - indicesOfLetter[i].begin();
				int high = upper_bound(indicesOfLetter[i].begin(), indicesOfLetter[i].end(), right) - indicesOfLetter[i].begin();
				high -= 1;
				int count = high - low + 1;
				if (count > 0 && count % 2) 
					numOfOddLetter++;
			}
			if ((numOfOddLetter % 2) ^ (tmplen % 2)) {
				result.push_back(false);
			}
			else {
				int need = numOfOddLetter / 2;
				result.push_back(need <= k);
			}
		}
		return result;
	}
};
int main()
{
	Solution sol;
	string s = "abcda";
	vector<vector<int>> queries = { {3,3,0},{1,2,0},{0,3,1},{0,3,2},{0,4,1} };
	vector<bool> result = sol.canMakePaliQueries(s, queries);
	for (auto a : result) cout << a << endl;
}
