// leetcode_238.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/product-of-array-except-self/
/*
Please solve it without division and in O(n).

Could you solve it with constant space complexity? 
(The output array does not count as extra space for the purpose of space complexity analysis.)

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> func(vector<int>& nums, int start, int end) {
		if (start == end) return { nums[start] };
		if (start + 1 == end) return { nums[end], nums[start] };
		vector<int> prevResult = func(nums, start, end - 1);
		int tmp = 1;
		for (int i = start; i <= end - 1; ++i) {
			tmp *= nums[i];
			prevResult[i] *= nums[end];
		}
		prevResult.push_back(tmp);
		return prevResult;
	}
	vector<int> productExceptSelf(vector<int>& nums) {
		// v1: O(n^2) TLE
		//int len = nums.size();
		//vector<int> result;
		//for (int i = 0; i < len; ++i) {
		//	int tmp = 1;
		//	for (int j = 0; j < len; ++j) {
		//		if (i != j)
		//			tmp *= nums[j];
		//	}
		//	result.push_back(tmp);
		//}
		//return result;

		// v2: division error while there is zeroes
		//int len = nums.size();
		//int bigProduct = 1;
		//for (int i = 0; i < len; ++i)
		//	bigProduct *= nums[i];
		//vector<int> result;
		//for (int i = 0; i < len; ++i)
		//	if (nums[i] == 0)
		//		result.push_back(0);
		//	else
		//		result.push_back(bigProduct / nums[i]);
		//return result;

		// v3: TLE
		// return func(nums, 0, nums.size() - 1);

		// v4 faster than 82.98% 
		//int len = nums.size();
		//vector<int> L(len);
		//vector<int> R(len);
		//vector<int> result(len);
		//// L[i] contains the product of all the elements to the left
		//L[0] = 1;
		//for (int i = 1; i < len; i++) {
		//	L[i] = nums[i - 1] * L[i - 1];
		//}
		//// R[i] contains the product of all the elements to the right
		//R[len - 1] = 1;
		//for (int i = len - 2; i >= 0; i--) {
		//	R[i] = nums[i + 1] * R[i + 1];
		//}
		//for (int i = 0; i < len; i++) {
		//	result[i] = L[i] * R[i];
		//}
		//return result;

		// v5: O(1) space  faster than 97.71% 
		int len = nums.size();
		vector<int> result(len);
		// the product of all the elements to the left
		result[0] = 1;
		for (int i = 1; i < len; i++) {
			result[i] = nums[i - 1] * result[i - 1];
		}
		// the product of all the elements to the right
		int R = 1;
		for (int i = len - 1; i >= 0; i--) {
			result[i] *= R;
			R *= nums[i];
		}
		return result;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
