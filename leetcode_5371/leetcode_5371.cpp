// leetcode_5371.cpp : This file contains the 'main' function. Program execution begins and ends there.
// todo https://leetcode.com/contest/weekly-contest-182/problems/find-all-good-strings/
/*
Given the strings s1 and s2 of size n, and the string evil. Return the number of good strings.

A good string has size n, it is alphabetically greater than or equal to s1, 
it is alphabetically smaller than or equal to s2, 
and it does not contain the string evil as a substring. 
Since the answer can be a huge number, return this modulo 10^9 + 7.

Input: n = 2, s1 = "aa", s2 = "da", evil = "b"
Output: 51
Explanation: 
There are 25 good strings starting with 'a': "aa","ac","ad",...,"az". 
Then there are 25 good strings starting with 'c': "ca","cc","cd",...,"cz" 
and finally there is one good string starting with 'd': "da".

Input: n = 8, s1 = "leetcode", s2 = "leetgoes", evil = "leet"
Output: 0
Explanation: All strings greater than or equal to s1 and smaller than or equal to s2 
start with the prefix "leet", therefore, there is not any good string.

Input: n = 2, s1 = "gx", s2 = "gz", evil = "x"
Output: 2

Constraints:

s1.length == n
s2.length == n
1 <= n <= 500
1 <= evil.length <= 50
All strings consist of lowercase English letters.
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        // find prefix
        // calculate s1->s2 counts, 
        // calculate s1->s2 counts with evil
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
