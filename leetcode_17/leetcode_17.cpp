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

// v1: faster than 59.59%
class Solution {
	unordered_map<char, string> mmap = { 
		{'2', "abc"}, {'3', "def"}, 
		{'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, 
		{'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} 
	};
	vector<string> result;
public:
	void backtrack(string combination, string next_digits) {
		if (next_digits.length() == 0) 
			result.push_back(combination);
		else {
			for (char letter : mmap[next_digits[0]]) {
				backtrack(combination + letter, next_digits.substr(1));
			}
		}
	}
	vector<string> letterCombinations(string digits) {
		if (digits.length() != 0) 
			backtrack("", digits);
		return result;
	}
};


int main()
{
    std::cout << "Hello World!\n";
}
