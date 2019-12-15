// leetcode_5124.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://leetcode.com/contest/weekly-contest-167/problems/sequential-digits/
/*
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.



Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]


Constraints:

10 <= low <= high <= 10^9

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> vec;
        int lowNumOfDigits = 2, highNumOfDigits = 2;        
        while (pow(10, lowNumOfDigits) <= low)
            lowNumOfDigits++;        
        while (pow(10, highNumOfDigits) <= high)
            highNumOfDigits++;
        for (int i = lowNumOfDigits; i <= highNumOfDigits; ++i) {
            for (int j = 1; (j+i-1) <= 9; ++j) {
                int result = 0;
                for (int k = j; k <= (j + i - 1); ++k) {
                    result = 10 * result + k;
                }
                if (low <= result && result <= high)
                    vec.push_back(result);
            }
        }
        return vec;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
