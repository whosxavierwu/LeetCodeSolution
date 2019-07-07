// leetcode_169.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/majority-element/
//Given an array of size n, find the majority element.The majority element is the element that appears more than  n / 2  times.
//You may assume that the array is non - empty and the majority element always exist in the array.

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		// version 1: sort
		//sort(nums.begin(), nums.end());
		//int len = nums.size();
		//return nums[len / 2];
		
		// version 2: map
		//map<int, int> num2count;
		//int len = nums.size();
		//int isExisted = 0;
		//for (int i = 0; i < len; i++) {
		//	isExisted = num2count.count(nums[i]);
		//	if (!isExisted) 
		//		num2count[nums[i]] = 0;
		//	num2count[nums[i]] += 1;
		//	if (num2count[nums[i]] > len / 2)
		//		return nums[i];
		//}
		//return nums[0];

		// version 1&2 is basicly same...

		// version 3: faster, but not enough...
		//int key = 0;
		//int count_of_key = 0;
		//int len = nums.size();
		//int tmp_len = 0;
		//vector<int> nums_tmp(0);
		//vector<int> nums_smaller(0);
		//vector<int> nums_bigger(0);
		//nums_tmp.assign(nums.begin(), nums.end());
		//while (nums_tmp.size() > 0) {
		//	nums_smaller.clear();
		//	nums_bigger.clear();
		//	key = nums_tmp[0];
		//	count_of_key = 1;
		//	tmp_len = nums_tmp.size();
		//	for (int i = 1; i < tmp_len; i++) {
		//		if (nums_tmp[i] == key)
		//			count_of_key++;
		//		else if (nums_tmp[i] < key)
		//			nums_smaller.push_back(nums_tmp[i]);
		//		else
		//			nums_bigger.push_back(nums_tmp[i]);
		//	}
		//	if (count_of_key > len / 2)
		//		return key;
		//	else if (nums_bigger.size() > nums_smaller.size())
		//		nums_tmp = nums_bigger;
		//	else
		//		nums_tmp = nums_smaller;
		//}
		//return nums[0];

		// ersion 4: this algo seems really cool, but performs like version 3
		int count = 0; 
		int key = 0; 
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			if (count == 0)
				// 意味着前面遍历过的数列里面 正好key出现了一半 并且被反对了一半 
				// 这时候可以直接忽略前面的数据 无论key是不是正确的
				// 假如不是 那么都是在少数里面砍掉数据 正解还是占多数
				// 假如是 那么两边势力同时去掉相同数量 正解依旧不变
				key = nums[i];
			count += (nums[i] == key) ? 1 : -1;
		}
		return key;

	}
};

int main()
{
    std::cout << "Hello World!\n";
}

