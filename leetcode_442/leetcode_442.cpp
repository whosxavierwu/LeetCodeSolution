// leetcode_442.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		// v1 faster than 70.19% 
		vector<int> result;
		int len = nums.size();
		for (int i = 0; i < len; ++i) {
			int next = abs(nums[i]) - 1;
			if (nums[next] < 0)
				result.push_back(next + 1);
			nums[next] = -abs(nums[next]);
		}
		return result;

		// v2 faster than 8.33% why ???
		//vector<int> result;
		//int len = nums.size();
		//for (int i = 0; i < len; ++i) {
		//	int next = abs(nums[i]) - 1;
		//	if (nums[next] < 0)
		//		result.push_back(next + 1);
		//	else
		//		nums[next] = -nums[next];
		//}
		//return result;

		// v3: faster than 88.12% 
		//int n = nums.size();
		//vector<int> result;
		//for (int i = 0; i < n; ++i) {
		//	int prev_value;
		//	while (nums[i] - 1 != i) {
		//		prev_value = nums[i];
		//		if (nums[i] - 1 != i)
		//			swap(nums[i], nums[nums[i] - 1]);
		//		else
		//			break;
		//		if (nums[i] == prev_value)
		//			break;
		//	}
		//}
		//for (int i = 0; i < n; ++i) {
		//	if (nums[i] - 1 != i && nums[i] == nums[nums[i] - 1])
		//		result.push_back(nums[i]);
		//}
		//return result;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
