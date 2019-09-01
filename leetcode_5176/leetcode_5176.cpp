// leetcode_5176.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/

/*
With respect to a given puzzle string, a word is valid if both the following conditions are satisfied:
word contains the first letter of puzzle.
For each letter in word, that letter is in puzzle.
For example, if the puzzle is "abcdefg", then valid words are "faced", "cabbage", and "baggage"; 
while invalid words are "beefed" (doesn't include "a") and "based" (includes "s" which isn't in the puzzle).
Return an array answer, where answer[i] is the number of words in the given word list words 
that are valid with respect to the puzzle puzzles[i].

Input:
words = ["aaaa","asas","able","ability","actt","actor","access"],
puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
Output: [1,1,3,2,4,0]
Explanation:
1 valid word for "aboveyz" : "aaaa"
1 valid word for "abrodyz" : "aaaa"
3 valid words for "abslute" : "aaaa", "asas", "able"
2 valid words for "absoryz" : "aaaa", "asas"
4 valid words for "actresz" : "aaaa", "asas", "actt", "access"
There're no valid words for "gaswxyz" cause none of the words in the list contains letter 'g'.

1 <= words.length <= 10^5
4 <= words[i].length <= 50
1 <= puzzles.length <= 10^4
puzzles[i].length == 7
words[i][j], puzzles[i][j] are English lowercase letters.
Each puzzles[i] doesn't contain repeated characters.
*/

#include <iostream>
#include <vector>
#include <bitset>
#include <set>
using namespace std;

class Solution {
public:
	vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
		// TLE
		// since the max length of puzzle is 7, words should not have >7 letters
		//vector<bitset<26>> bitsOfWord;
		//bitset<26> bits;
		//for (string& word : words) {
		//	bits.reset();
		//	for (char letter : word)
		//		bits.set(letter - 'a');
		//	if (bits.count() > 7) continue;
		//	bitsOfWord.push_back(bits);
		//}
		//vector<int> result;
		//bitset<26> bitsOfCurPuzzle;
		//for (string& puzzle : puzzles) {
		//	bitsOfCurPuzzle.reset();
		//	for (char letter : puzzle)
		//		bitsOfCurPuzzle.set(letter - 'a');
		//	int count = 0;
		//	for (bitset<26>& bitsOfCurWord : bitsOfWord) {
		//		if ((bitsOfCurWord | bitsOfCurPuzzle) == bitsOfCurPuzzle 
		//			&& bitsOfCurWord.test(puzzle[0] - 'a'))
		//			++count;
		//	}
		//	result.push_back(count);
		//}
		//return result;

		// v2: 1716 ms, faster than 7.69% 
		vector<int> result;
		vector<int> bitsOfWord;
		for (string& w : words) {
			int bit = 0;
			set<char> letters;
			for (char c : w) {
				bit = bit | (1 << (c - 'a'));
				letters.insert(c);
			}
			if (letters.size() <= 7)
				bitsOfWord.push_back(bit);
		}
		for (string& puzzle : puzzles) {
			int num = 0;
			int bitsOfCurPuzzle = 0;
			for (char c: puzzle) 
				bitsOfCurPuzzle = bitsOfCurPuzzle | (1 << (c - 'a'));
			int firstBit = 1 << (puzzle[0] - 'a');
			for (int bitsOfCurWord : bitsOfWord) {
				if ((bitsOfCurWord | bitsOfCurPuzzle) == bitsOfCurPuzzle && (bitsOfCurWord & firstBit) == firstBit)
					++num;
			}
			result.push_back(num);
		}
		return result;
	}
};
int main()
{
	Solution sol;
	vector<string> words = { "aaaa","asas","able","ability","actt","actor","access" };
	vector<string> puzzles = { "aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz" };
	vector<int> result = sol.findNumOfValidWords(words, puzzles);
	for (int n : result)
		cout << n << endl;
}
