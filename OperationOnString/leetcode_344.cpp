// https://leetcode.com/problems/reverse-string/
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        char ch;
        int len = s.size();
        if (len <= 1) 
            return;
        int mid = (len - 1) / 2;
        for (int i = 0; i <= mid; ++i) {
            ch = s[i];
            s[i] = s[len - i - 1];
            s[len - i - 1] = ch;
        }
    }
};

