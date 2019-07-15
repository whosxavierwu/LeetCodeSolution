// leetcode_72.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Edit distance; three operation: insert/delete/replace

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		// dist[0, j] = j; dist[i, 0] = i;
		// dist[i, j] = min( dist[i-1,j]+1, dist[i,j-1]+1, dist[i-1,j-1]+1{w1[i]==w2[j]} )
		int len1 = word1.size(), len2 = word2.size();
		if (len1 == 0 || len2 == 0)
			return len1 + len2;

		// v1: faster than 76.82% 
		//vector<vector<int>> mat(len1+1, vector<int>(len2+1, 0));
		//int i = 0, j = 0; 
		//for (i = 0; i <= len1; ++i)
		//	mat[i][0] = i;
		//for (j = 0; j <= len2; ++j)
		//	mat[0][j] = j;
		//for (i = 1; i <= len1; ++i) {
		//	for (j = 1; j <= len2; ++j) {
		//		if (word1[i - 1] == word2[j - 1])
		//			mat[i][j] = mat[i - 1][j - 1];
		//		else {
		//			mat[i][j] = fmin(mat[i - 1][j] + 1, mat[i][j - 1] + 1);
		//			mat[i][j] = fmin(mat[i - 1][j - 1] + 1, mat[i][j]);
		//		}
		//	}
		//}
		//return mat[len1][len2];

		// v2: faster than 93.71% 
		vector<int> vec(len2 + 1, 0);
		int i = 0, j = 0;
		for (j = 0; j <= len2; ++j)
			vec[j] = j;
		for (i = 1; i <= len1; ++i) {
			int old = i - 1;  // mat[i - 1][j - 1]
			vec[0] = i;
			for (j = 1; j <= len2; ++j) {
				int temp = vec[j];
				if (word1[i - 1] == word2[j - 1])
					vec[j] = old;
				else {
					int tmp = fmin(vec[j] + 1, vec[j - 1] + 1);
					tmp = fmin(old + 1, tmp);
					vec[j] = tmp;
				}
				old = temp;
			}
		}
		return vec[len2];
	}
};

int main()
{
	Solution sol;
	int result = sol.minDistance("sea", "eat");
	cout << result << endl;
}

