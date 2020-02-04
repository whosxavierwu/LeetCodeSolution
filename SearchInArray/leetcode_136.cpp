// leetcode_136.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/single-number/
//Given a non-empty array of integers, every element appears twice except for one. Find that single one.
//Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory ?


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		// v1: use xor, really cool version, but not fast enough, beats 77%
		//int a = 0;
		//int len = nums.size();
		//for (int i = 0; i < len; ++i)
		//	a ^= nums[i];
		//return a;

		// v2: use hash table; cost same as v1
		unordered_map<int, bool> map;
		int len = nums.size();
		for (int i = 0; i < len; ++i) {
			if (map.count(nums[i])) {
				map.erase(nums[i]);
			}
			else {
				map.insert(pair<int, bool>(nums[i], true));
			}
		}
		return map.begin()->first;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

