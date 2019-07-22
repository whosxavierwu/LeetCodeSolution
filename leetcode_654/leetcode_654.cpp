// leetcode_654.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/maximum-binary-tree/
/*
Given an integer array with no duplicates. 
A maximum tree building on this array is defined as follow:
1. The root is the maximum number in the array.
2. The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
3. The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* constructFunc(vector<int>& nums, int start, int end) {
		int maxIdx = start;
		for (int i = start + 1; i <= end; ++i) {
			if (nums[i] > nums[maxIdx])
				maxIdx = i;
		}
		TreeNode* root = new TreeNode(nums[maxIdx]);
		if (maxIdx - 1 > start)
			root->left = constructFunc(nums, start, maxIdx - 1);
		else if (maxIdx - 1 == start)
			root->left = new TreeNode(nums[start]);
		if (end > maxIdx + 1)
			root->right = constructFunc(nums, maxIdx + 1, end);
		else if (end == maxIdx + 1)
			root->right = new TreeNode(nums[end]);
		return root;
	}
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		// v1: recursive, faster than 83.17% 
		//return constructFunc(nums, 0, nums.size() - 1);

		//// v2: one pass  faster than 83.17% why so slow???
		//// https://leetcode.com/problems/maximum-binary-tree/discuss/106146/C%2B%2B-O(N)-solution
		//vector<TreeNode*> stk;
		//for (int i = 0; i < nums.size(); ++i) {
		//	TreeNode* cur = new TreeNode(nums[i]);
		//	// top of stack is always >= nums[i]
		//	while (!stk.empty() && stk.back()->val < nums[i]) {
		//		// refreshing to make cur->left the largest num 
		//		// that is before nums[i]
		//		cur->left = stk.back();
		//		stk.pop_back();
		//	}
		//	// top of stack >= cur
		//	// and cur is on the right of stack.top
		//	if (!stk.empty())
		//		stk.back()->right = cur;
		//	stk.push_back(cur);
		//}
		//// the greatest num
		//return stk.front();

		//// v3: faster than 68.71% 
		//map<int, TreeNode*> q;
		//for (int num : nums) {
		//	auto it = q.insert({ num, new TreeNode(num) }).first;
		//	if (it != q.begin()) {
		//		it->second->left = next(it, -1)->second;
		//		q.erase(q.begin(), it);
		//	}
		//	if (next(it, 1) != q.end()) next(it, 1)->second->right = it->second;
		//}
		//return q.rbegin()->second;

		// v4 faster than 83.17% ...
		vector<TreeNode*> s{ new TreeNode(nums[0]) };
		for (int i = 1; i < nums.size(); ++i) {
			TreeNode* cur = new TreeNode(nums[i]);
			auto it = upper_bound(s.rbegin(), s.rend(), cur,
				[](const TreeNode* a, const TreeNode* b) { return a->val < b->val; });
			if (it != s.rend()) (*it)->right = cur;
			if (it != s.rbegin()) cur->left = *next(it, -1);
			s.resize(distance(it, s.rend()));
			s.push_back(cur);
		}
		return s.front();

	}
};

int main()
{
	Solution sol;
	vector<int> nums = { 3,2,1,6,0,5 };
	TreeNode* root = sol.constructMaximumBinaryTree(nums);
}
