// leetcode_5367.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-181/problems/longest-happy-prefix/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lenOfPrefix(n, 0);
        int len = 0;
        for (int i = 1; i < n; ++i) {
            if (s[len] == s[i]) {  // 0,...,len ; ?,...,i
                ++len;
                lenOfPrefix[i] = len; 
            }
            else if (len > 0) {
                // in this case, let len down & check i again
                len = lenOfPrefix[len - 1];
                --i;
            }
            else {  // s[i]!=s[0], so no prefix for s[0]...s[i]
                lenOfPrefix[i] = 0;
            }
        }
        return s.substr(0, lenOfPrefix[n - 1]);
    }
};

int main()
{
    Solution sol;
    cout << sol.longestPrefix("level") << endl;
    cout << sol.longestPrefix("ababab") << endl;
    cout << sol.longestPrefix("leetcodeleet") << endl;
    cout << sol.longestPrefix("a") << endl;
}
