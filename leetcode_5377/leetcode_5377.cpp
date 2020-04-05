// leetcode_5377.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-183/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int count = 0;
        while (s.size() != 1) {
            if (s.back() == '1') {
                // plus 1
                int i = s.size() - 2;
                for (; i >= 0; --i)
                    if (s[i] == '0')
                        break;
                if (i >= 0) {
                    s[i] = '1';
                    for (int j = i + 1; j < s.size(); ++j)
                        s[j] = '0';
                }
                else {
                    s = "1" + string(s.size(), '0');
                }
            }
            else {
                s.pop_back();
            }
            count++;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    string s = "1111011110000011100000110001011011110010111001010111110001";
    cout << sol.numSteps(s) << endl;
}
