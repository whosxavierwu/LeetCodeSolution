// leetcode_1154.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int dayOfYear(string date) {
		int year = stoi(date.substr(0, 4));
		int month = stoi(date.substr(5, 2));
		int day = stoi(date.substr(8, 2));
		vector<int> daysOfMonth = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		// check if it's leap year
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			daysOfMonth[2] = 29;
		// calculate days so far
		int days = 0;
		for (int i = 1; i < month; ++i) {
			days += daysOfMonth[i];
		}
		days += day;
		return days;
	}
};
int main()
{
	Solution sol;
	int result = 0;
	result = sol.dayOfYear("2019-01-09");
	cout << result << endl;
	result = sol.dayOfYear("2019-02-10");
	cout << result << endl;
	result = sol.dayOfYear("2003-03-01");
	cout << result << endl;
	result = sol.dayOfYear("2004-03-01");
	cout << result << endl;
}
