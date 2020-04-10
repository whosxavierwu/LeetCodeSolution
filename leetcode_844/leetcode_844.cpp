// leetcode_844.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/backspace-string-compare/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int ps = S.size() - 1;
        int pt = T.size() - 1;
        while (ps >= 0 || pt >= 0) {
            int cnt = 0;
            while (ps >= 0 && S[ps] == '#') {
                cnt = 0;
                do {
                    if (S[ps] == '#')
                        cnt++;
                    else
                        cnt--;
                    ps--;
                } while (ps >= 0 && cnt > 0);
            }
            while (pt >= 0 && T[pt] == '#') {
                cnt = 0;
                do {
                    if (T[pt] == '#')
                        cnt++;
                    else
                        cnt--;
                    pt--;
                } while (pt >= 0 && cnt > 0);
            }
            if (ps < 0 && pt < 0)
                return true;
            else if ((ps >= 0) ^ (pt >= 0))
                return false;
            else if (S[ps] != T[pt])
                return false;
            else {
                ps--;
                pt--;
            }
        }
        
        return true;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
