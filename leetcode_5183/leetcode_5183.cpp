// leetcode_5183.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-153/problems/day-of-the-week/
/*
Given a date, return the corresponding day of the week for that date.

The input is given as three integers representing the day, month and year respectively.

Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.

The given dates are valid dates between the years 1971 and 2100.

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string dayOfTheWeek(int day, int month, int year) {
		vector<string> results = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
		if (month < 3) {
			year -= 1;
			month += 12;
		}
		int c = year / 100;
		int y = year % 100;
		int week = (c / 4 - 2 * c) + (y + y / 4) + 13 * (month + 1) / 5 + day - 1;
		while (week < 0)
			week += 7;
		return results[week % 7];
	}
};
int main()
{
	Solution sol;
	cout << sol.dayOfTheWeek(31, 8, 2019) << endl;
	cout << sol.dayOfTheWeek(18, 7, 1999) << endl;
	cout << sol.dayOfTheWeek(15, 8, 1993) << endl;
}
