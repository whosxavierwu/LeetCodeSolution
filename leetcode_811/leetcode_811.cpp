// leetcode_811.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<string> subdomainVisits(vector<string>& cpdomains) {
		unordered_map<string, int> mmap;
		for (string& cpdomain: cpdomains) {
			int idx = cpdomain.find(' ');
			int cnt = stoi(cpdomain.substr(0, idx + 1));
			string domain = cpdomain.substr(idx + 1, cpdomain.length());
			mmap[domain] = cnt;
			int pos = 0;
			while (true) {
				pos = domain.find('.', pos + 1);
				if (pos == domain.npos) break;
				string subdomain = domain.substr(pos + 1, domain.length());
				mmap[subdomain] += cnt;
			}
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
