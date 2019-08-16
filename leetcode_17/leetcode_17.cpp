// leetcode_17.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
	unordered_map<char, string> mmap = { 
		{'2', "abc"}, {'3', "def"}, 
		{'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, 
		{'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} 
	};
public:
	vector<string> letterCombinations(string digits) {
		int numOfDigits = digits.length();
		int numOfComb = 1;
		for (char digit : digits)
			numOfComb *= mmap[digit].length();
		// todo duplicate digit in digits?
		vector<string> result(numOfComb, string(numOfDigits, ' '));
		for (int digitIdx = 0; digitIdx < numOfDigits; ++digitIdx) {
			string letters = mmap[digits[digitIdx]];
			int letterLen = letters.length();
			int letterIdx = 0;
			for (int combIdx = 0; combIdx < numOfComb; ++combIdx) {
				result[combIdx][digitIdx] = letters[letterIdx];
				++letterIdx;
				if (letterIdx >= letterLen) letterIdx = 0;
			}
		}
		return result;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
