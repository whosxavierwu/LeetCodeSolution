// leetcode_5362.cpp : This file contains the 'main' function. Program execution begins and ends there.
// todo https://leetcode.com/contest/biweekly-contest-23/problems/construct-k-palindrome-strings/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        int len = s.size();
        if (len < k)
            return false;
        if (len == k)
            return true;
        vector<int> vec(26);
        for (char c : s)
            vec[c - 'a'] ++;
        // 2m, 2m+1
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
