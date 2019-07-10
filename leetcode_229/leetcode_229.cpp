// leetcode_229.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		float vote = 0.0;
		int key = 0;
		int tmp = 0;
		vector<int> result(0);
		int len = nums.size();
		
		for (int i = 0; i < len; ++i) {
			if (vote == 0.0)
				key = nums[i];
			if (key == nums[i])
				vote += 1.5;
			else
				vote -= 1.0;
		}
		if (vote > 0)
			result.push_back(key);

		if (!result.empty()) {
			tmp = result[0];
			vote = 0.0;
			for (int i = 0; i < len; ++i) {
				if (vote == 0.0)
					key = nums[i];
				if ((key != tmp) && (key == nums[i]))
					vote += 1.5;
				else
					vote -= 1.0;
			}
			if (vote > 0)
				result.push_back(key);
		}
		return result;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
