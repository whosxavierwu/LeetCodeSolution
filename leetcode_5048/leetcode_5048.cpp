// leetcode_5048.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int countCharacters(vector<string>& words, string chars) {
		vector<int> isInChars(26);
		for (char& c : chars)
			isInChars[c - 'a'] += 1;
		int result = 0;
		for (string& word : words) {
			vector<int> cntChar = isInChars;
			bool valid = true;
			for (char& c : word) {
				cntChar[c - 'a'] -= 1;
				if (cntChar[c - 'a'] < 0) {
					valid = false;
					break;
				}
			}
			if (valid) 
				result += word.length();
		}
		return result;
	}
};
int main()
{
	Solution sol;
	//vector<string> words = { "cat","bt","hat","tree" };
	//string chars = "atach";
	vector<string> words = { "hello","world","leetcode" };
	string chars = "welldonehoneyr";
	//vector<string> words = { 
	//	"dyiclysmffuhibgfvapygkorkqllqlvokosagyelotobicwcmebnpznjbirzrzsrtzjxhsfpiwyfhzyonmuabtlwin",
	//	"ndqeyhhcquplmznwslewjzuyfgklssvkqxmqjpwhrshycmvrb",
	//	"ulrrbpspyudncdlbkxkrqpivfftrggemkpyjl",
	//	"boygirdlggnh",
	//	"xmqohbyqwagkjzpyawsydmdaattthmuvjbzwpyopyafphx",
	//	"nulvimegcsiwvhwuiyednoxpugfeimnnyeoczuzxgxbqjvegcxeqnjbwnbvowastqhojepisusvsidhqmszbrnynkyop",
	//	"hiefuovybkpgzygprmndrkyspoiyapdwkxebgsmodhzpx",
	//	"juldqdzeskpffaoqcyyxiqqowsalqumddcufhouhrskozhlmobiwzxnhdkidr",
	//	"lnnvsdcrvzfmrvurucrzlfyigcycffpiuoo",
	//	"oxgaskztzroxuntiwlfyufddl",
	//	"tfspedteabxatkaypitjfkhkkigdwdkctqbczcugripkgcyfezpuklfqfcsccboarbfbjfrkxp",
	//	"qnagrpfzlyrouolqquytwnwnsqnmuzphne","eeilfdaookieawrrbvtnqfzcricvhpiv",
	//	"sisvsjzyrbdsjcwwygdnxcjhzhsxhpceqz",
	//	"yhouqhjevqxtecomahbwoptzlkyvjexhzcbccusbjjdgcfzlkoqwiwue",
	//	"hwxxighzvceaplsycajkhynkhzkwkouszwaiuzqcleyflqrxgjsvlegvupzqijbornbfwpefhxekgpuvgiyeudhncv",
	//	"cpwcjwgbcquirnsazumgjjcltitmeyfaudbnbqhflvecjsupjmgwfbjo",
	//	"teyygdmmyadppuopvqdodaczob",
	//	"qaeowuwqsqffvibrtxnjnzvzuuonrkwpysyxvkijemmpdmtnqxwekbpfzs",
	//	"qqxpxpmemkldghbmbyxpkwgkaykaerhmwwjonrhcsubchs" };
	//string chars = "usdruypficfbpfbivlrhutcgvyjenlxzeovdyjtgvvfdjzcmikjraspdfp";
	cout << sol.countCharacters(words, chars) << endl;
}
