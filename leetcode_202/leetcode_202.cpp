// leetcode_202.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/happy-number/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (n != 1 && s.find(n) == s.end()) {
            s.insert(n);
            int next = 0;
            while (n > 0) {
                next += (n % 10) * (n % 10);
                n /= 10;
            }
            n = next;
        }
        return n == 1;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
