// leetcode_1170.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
		vector<int> Q;
		vector<int> W;
		for (string query : queries) {
			sort(query.begin(), query.end());
			int cnt = 1;
			for (int i = 1; i < query.length(); ++i) {
				if (query[i] == query[0]) cnt++;
				else break;
			}
			Q.push_back(cnt);
		}
		for (string word: words) {
			sort(word.begin(), word.end());
			int cnt = 1;
			for (int i = 1; i < word.length(); ++i) {
				if (word[i] == word[0]) cnt++;
				else break;
			}
			W.push_back(cnt);
		}
		vector<int> result;
		for (int i = 0; i < Q.size(); ++i) {
			int cnt = 0;
			for (int j = 0; j < W.size(); ++j) {
				if (Q[i] < W[j])
					++cnt;
			}
			result.push_back(cnt);
		}
		return result;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
