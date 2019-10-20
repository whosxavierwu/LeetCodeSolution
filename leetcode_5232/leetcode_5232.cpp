// leetcode_5232.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-159/problems/replace-the-substring-for-balanced-string/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int balancedString(string s) {
		const string CHARS = "QWER";
		int n = s.size();
		vector<vector<int>> runCount(4, vector<int>(n + 1, 0));

		for (int i = 0; i < n; ++i) {
			runCount[0][i + 1] = runCount[0][i] + (s[i] == 'Q');
			runCount[1][i + 1] = runCount[1][i] + (s[i] == 'W');
			runCount[2][i + 1] = runCount[2][i] + (s[i] == 'E');
			runCount[3][i + 1] = runCount[3][i] + (s[i] == 'R');
		}

		// dont really understand this solution...
		int low = 0, high = n;
		while (low < high) {
			int mid = (low + high) / 2;
			bool works = false;

			for (int i = 0; i + mid <= n; i++) {
				int now[4];
				bool good = true;
				for (int c = 0; c < 4; c++) {
					now[c] = runCount[c][i] + (runCount[c][n] - runCount[c][i + mid]);
					if (now[c] > n / 4) good = false;
				}
				works = works || good;
			}

			if (works) high = mid;
			else low = mid + 1;
		}
		return low;
	}
};


int main()
{
	Solution sol;
	//cout << sol.balancedString("QWER") << endl;
	//cout << sol.balancedString("QQWE") << endl;
	//cout << sol.balancedString("QQQW") << endl;
	//cout << sol.balancedString("QQQQ") << endl;
	cout << sol.balancedString("WWEQERQWQWWRWWERQWEQ") << endl;
	// 0, 3, -1, -2    20/4=5     5, 8, 4, 3
	// find the min string containing 3W
}
