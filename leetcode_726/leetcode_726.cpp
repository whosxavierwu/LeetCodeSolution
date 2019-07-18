// leetcode_726.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/number-of-atoms/

/*
All atom names consist of lowercase letters, except for the first character which is uppercase.
The length of formula will be in the range [1, 1000].
formula will only consist of letters, digits, and round parentheses, and is a valid formula as defined in the problem.
*/

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	void countFunc(string S, int coef, map<string, int> &cntMap) {
		int len = S.length();
		for (int i = 0; i < len; ) {
			if (S[i] == '(') {
				int left = 1, right = 0;
				int lParenthesis = i;
				for (++i; left != right; ++i) {
					if (S[i] == '(')
						++left;
					else if (S[i] == ')')
						++right;
				}
				// i is after )
				int rParenthesis = i - 1;
				// find digit 
				for (; i < len; ++i) {
					if (!isdigit(S[i]))
						break;
				}
				// i is not a digit
				if (rParenthesis + 1 == i) {
					// no num
					countFunc(S.substr(lParenthesis + 1, rParenthesis - lParenthesis - 1), coef, cntMap);
				}
				else {
					// has num
					countFunc(S.substr(lParenthesis + 1, rParenthesis - lParenthesis - 1), 
						coef * stoi(S.substr(rParenthesis + 1, i - rParenthesis - 1)), 
						cntMap);
				}
			}
			else if (isupper(S[i])) {
				string atom = "";
				atom += S[i];
				string cnt = "";
				for (++i; i < len; ++i) {
					if (islower(S[i])) {
						atom += S[i];
					}
					else if (isdigit(S[i])) {
						cnt += S[i];
					}
					else {
						break;
					}
				}
				// i is parenthesis or upper
				int tmp_coef = (cnt == "") ? 1 : stoi(cnt);
				if (cntMap.count(atom) == 0)
					cntMap[atom] = tmp_coef * coef;
				else
					cntMap[atom] = cntMap[atom] + tmp_coef * coef;
			}
		}
	}
	string countOfAtoms(string formula) {
		// v1: faster than 79.02%
		map<string, int> cntMap;
		countFunc(formula, 1, cntMap);
		string result = "";
		map<string, int>::iterator iter;
		for (iter = cntMap.begin(); iter != cntMap.end(); ++iter) {
			result += iter->first;
			if (iter->second > 1)
				result += to_string(iter->second);
		}
		return result;
	}
};

int main()
{
	Solution sol;
	cout << sol.countOfAtoms("H2O") << endl;
	cout << sol.countOfAtoms("Mg(OH)2") << endl;
	cout << sol.countOfAtoms("K4(ON(SO3)2)2") << endl;
	return 0;
}

