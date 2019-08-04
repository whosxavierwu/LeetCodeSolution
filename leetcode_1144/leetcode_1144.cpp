// leetcode_1144.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int movesToMakeZigzag(vector<int>& nums) {
		int movesPickingEven = 0, movesPickingOdd = 0;
		for (int i = 0; i < nums.size(); ++i) {
			int leftNum = i > 0 ? nums[i - 1] : INT_MAX;
			int rightNum = (i + 1) < nums.size() ? nums[i + 1] : INT_MAX;
			// suppose operating on i
			int a = INT_MIN, b = INT_MIN;
			if (leftNum <= nums[i])
				a = nums[i] - leftNum + 1;
			if (rightNum <= nums[i])
				b = nums[i] - rightNum + 1;
			int result = 0;
			result = fmax(a, result);
			result = fmax(b, result);
			if (i % 2 == 0) {
				movesPickingOdd += result;
			}
			else {
				movesPickingEven += result;
			}
		}
		return fmin(movesPickingEven, movesPickingOdd);
	}
};

int main()
{
	//vector<int> arr = { 9,6,1,6,2 };
	vector<int> arr = { 2,7,10,9,8,9 };
	Solution sol;
	int result = sol.movesToMakeZigzag(arr);
	cout << result << endl;
	return 0;
}

