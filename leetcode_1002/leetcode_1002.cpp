// leetcode_1002.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/find-common-characters/submissions/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<string> commonChars(vector<string>& A) {
		// faster than 96.59% 
		vector<int> charCount(26, -1);
		for (string& s : A) {
			vector<int> tmpCount(26);
			for (char& c : s) {
				tmpCount[c - 'a']++;
			}
			for (int i = 0; i < 26; ++i) {
				charCount[i] = (charCount[i] < 0) ? tmpCount[i] : min(charCount[i], tmpCount[i]);
			}
		}
		vector<string> result;
		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < charCount[i]; ++j) {
				result.push_back(string(1, 'a' + i));
			}
		}
		return result;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}
