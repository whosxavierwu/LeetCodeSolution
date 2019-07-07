// leetcode_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Solution.h"

#include <iostream>


int main()
{
	vector<int> v = {-3, 4, 3, 90};
	int target = 0; 
	Solution solution = Solution();
	vector<int> result = solution.twoSum(v, target);
	cout << result[0] << result[1] << endl;
	return 0;
}
