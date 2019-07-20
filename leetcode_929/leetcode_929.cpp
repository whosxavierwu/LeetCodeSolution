// leetcode_929.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		// v1: faster than 59.84% 
		set<string> uniqueEmails;
		for (string email : emails) {
			int len = email.length();
			string newEmail = "";
			bool ignore = false;
			for (int i = 0; i < len; ++i) {
				if (email[i] == '@') {
					newEmail += email.substr(i, len - i);
					break;
				}else if (email[i] == '.' || ignore) {
					;
				}
				else if (email[i] == '+') {
					ignore = true;
				}
				else{
					newEmail += email[i];
				}
			}
			uniqueEmails.insert(newEmail);
		}
		return uniqueEmails.size();
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
