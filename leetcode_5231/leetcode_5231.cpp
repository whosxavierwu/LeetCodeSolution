// leetcode_5231.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-159/problems/remove-sub-folders-from-the-filesystem/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<string> removeSubfolders(vector<string>& folder) {
		sort(folder.begin(), folder.end());
		int len = folder.size();
		vector<string> result;
		result.push_back(folder[0]);
		string root = folder[0] + "/";
		int rootLen = root.length();
		for (int i = 1; i < len; ++i) {
			if (folder[i].substr(0, rootLen) != root) {
				result.push_back(folder[i]);
				root = folder[i] + "/";
				rootLen = root.length();
			}
		}
		return result;
	}
};
int main()
{
	Solution sol;
	//vector<string> folder = { "/a","/a/b","/c/d","/c/d/e","/c/f" };
	//vector<string> folder = { "/a","/a/b/c","/a/b/d" };
	vector<string> folder = { "/a/b/c","/a/b/ca","/a/b/d" };
	vector<string> result = sol.removeSubfolders(folder);
	for (string s : result)
		cout << s << endl;
}
