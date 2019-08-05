// leetcode_811.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// faster than 91.04%
class Solution {
public:
	vector<string> subdomainVisits(vector<string>& cpdomains) {
		unordered_map<string, int> mmap;
		for (string& cpdomain: cpdomains) {
			int idx = cpdomain.find(' ');
			int cnt = stoi(cpdomain.substr(0, idx));
			string domain = cpdomain.substr(idx + 1);
			for (int i = 0; i < domain.length(); ++i) {
				if (domain[i] == '.')
					mmap[domain.substr(i + 1)] += cnt;
			}
			mmap[domain] += cnt;
		}
		vector<string> result;
		for (auto iter = mmap.begin(); iter != mmap.end(); ++iter) {
			result.push_back(to_string(iter->second) + " " + iter->first);
		}
		return result;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
