// leetcode_5071.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/biweekly-contest-9/problems/find-smallest-common-element-in-all-rows/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
	int smallestCommonElement(vector<vector<int>>& mat) {
		int N = mat.size();
		int M = mat[0].size();
		vector<int> vec = mat[0];
		for (int n = 1; n < N; ++n) {
			int left1 = 0, left2 = 0, right1 = vec.size() - 1, right2 = M - 1;
			vector<int> tmp;
			while (left1 <= right1 && left2 <= right2) {
				if (vec[left1] == mat[n][left2]) {
					tmp.push_back(vec[left1]);
					++left1;
					++left2;
				}
				else if (vec[left1] < mat[n][left2]) {
					++left1;
				}
				else {
					++left2;
				}
			}
			vec = tmp;
		}
		return vec.empty() ? -1 : vec[0];
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> mat = { {1,2,3,4,5} ,{2,4,5,8,10},{3,5,7,9,11},{1,3,5,7,9} };
	cout << sol.smallestCommonElement(mat) << endl;
}
