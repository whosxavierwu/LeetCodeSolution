// leetcode_15.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/3sum/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int len = nums.size();
		vector<vector<int>> results(0);
		if (len <= 3) {
			if ((len == 3) && (nums[0] + nums[1] + nums[2] == 0)) 
				results.push_back(nums);
			return results;
		}

		// v2: faster than 38.97%
		//sort(nums.begin(), nums.end());
		//for (int i = 0; i < len; ++i) {
		//	if (i != 0 && nums[i - 1] == nums[i])
		//		// help to drop duplicates?
		//		continue;
		//	int j = i + 1, k = len - 1;
		//	while (j < k) {
		//		if (nums[i] + nums[j] + nums[k] > 0)
		//			--k;
		//		else if (nums[i] + nums[j] + nums[k] < 0)
		//			++j;
		//		else {
		//			results.push_back({ nums[i], nums[j], nums[k] });
		//			// help to drop dupllicates?
		//			while (j < k && nums[j + 1] == nums[j]) ++j;
		//			while (j < k && nums[k - 1] == nums[k]) --k;
		//			++j;
		//			--k;
		//		}
		//	}
		//}
		//return results;

		// v3: faster than 95.13%
		//sort(nums.begin(), nums.end());
		//for (int i = 0; i < len; ++i) {
		//	int target = -nums[i];
		//	int front = i + 1;
		//	int back = len - 1;

		//	// front>i & back>i, so both of them less than target.
		//	// if target<0, front<0 and back<0, so sum could never be zero
		//	if (target < 0)
		//		break;  

		//	while (front < back) {
		//		int sum = nums[front] + nums[back];
		//		// nums[front]<nums[back]
		//		if (sum < target)
		//			// we need to +front; since we cant +back
		//			++front;  
		//		else if (sum > target)
		//			// we need to -back; since we cant -front
		//			--back;
		//		else {
		//			vector<int> triplet = { nums[i], nums[front], nums[back] };
		//			results.push_back(triplet);

		//			// drop duplicates
		//			while (front < back && nums[front] == triplet[1]) ++front;
		//			while (front < back && nums[back] == triplet[2]) --back;
		//		}
		//	}
		//	// speed up 
		//	while (i + 1 < len && nums[i + 1] == nums[i]) ++i;
		//}
		//return results;

		// v4: faster than 95.13%
		sort(nums.begin(), nums.end());
		for (int i = 0; i < len - 2; ++i) {
			int a = nums[i];
			if (a > 0) break;
			if (i > 0 && a == nums[i - 1]) continue;
			for (long j = i + 1, k = len - 1; j < k;) {
				int b = nums[j];
				int c = nums[k];
				int sum = a + b + c;
				if (sum == 0) {
					results.push_back(vector<int>({ a, b, c }));
					while (j < k && b == nums[++j]);
					while (j < k && c == nums[--k]);
				}
				else if (sum > 0) {
					--k;
				}
				else {
					++j;
				}
			}
		}
		return results;

	}
};

int main()
{
    std::cout << "Hello World!\n";
}

