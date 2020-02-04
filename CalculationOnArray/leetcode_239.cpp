// leetcode_239.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/sliding-window-maximum/

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		//// v1: faster than 17.30%, too slow!!!
		//int len = nums.size();
		//int numOfResults = len - k + 1;
		//vector<int> results(numOfResults);
		//int resultId = 0;
		//// simple case
		//if (len <= 1)
		//	return nums;
		//if (k == 1)
		//	return nums;
		//if (k == len) {
		//	int max = INT_MIN;
		//	for (int i = 0; i < len; ++i)
		//		if (nums[i] > max)
		//			max = nums[i];
		//	results[0] = max;
		//	return results;
		//}
		//deque<int> deq;
		//for (resultId = 0; resultId < numOfResults; ++resultId) {
		//	// nums[resultId: resultId+k-1]
		//	if (deq.empty()) {
		//		for (int i = resultId; i < (resultId + k - 1); ++i) {
		//			if (deq.empty() || nums[i] >= deq.back())
		//				deq.push_back(nums[i]);
		//		}
		//	}
		//	if (nums[resultId + k - 1] >= deq.back()) {
		//		deq.push_back(nums[resultId + k - 1]);
		//		results[resultId] = nums[resultId + k - 1];
		//	}
		//	else {
		//		results[resultId] = deq.back();
		//	}
		//	deq.pop_front();
		//}
		//return results;

		// v2: faster than 87.57%, why???
		deque<int> dq;  // store idx instead of value
		vector<int> ans;
		for (int i = 0; i < nums.size(); i++) {
			if (!dq.empty() && dq.front() == i - k) 
				dq.pop_front();
			while (!dq.empty() && nums[dq.back()] < nums[i])
				dq.pop_back();
			// now dp.back() >= nums[i]
			dq.push_back(i);
			if (i >= k - 1) 
				ans.push_back(nums[dq.front()]);
		}
		return ans;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
