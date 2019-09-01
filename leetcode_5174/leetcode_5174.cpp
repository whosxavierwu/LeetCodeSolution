// leetcode_5174.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
A dieter consumes calories[i] calories on the i-th day.  
For every consecutive sequence of k days, they look at T, 
the total calories consumed during that sequence of k days:

If T < lower, they performed poorly on their diet and lose 1 point;
If T > upper, they performed well on their diet and gain 1 point;
Otherwise, they performed normally and there is no change in points.
Return the total number of points the dieter has after all calories.length days.

Note that: The total points could be negative.

1 <= k <= calories.length <= 10^5
0 <= calories[i] <= 20000
0 <= lower <= upper
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
		int len = calories.size();
		int result = 0;
		int T = 0;
		for (int i = 0; i < k - 1; ++i) T += calories[i];
		for (int i = k - 1; i < len; ++i) {
			// [i-k+1]~[i]
			T = T + calories[i] - (i >= k ? calories[i - k] : 0);
			if (T < lower) result--;
			else if (T > upper) result++;
		}
		return result;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
