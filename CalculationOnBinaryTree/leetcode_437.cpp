// leetcode_437.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/path-sum-iii/
/*
You are given a binary tree in which each node contains an integer value.
Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, 
but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
*/

#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int pathSum(TreeNode* root, int sum, bool isStarted) {
		if (!root) return 0;
		int result = (root->val == sum);
		if (!isStarted) {  // in this case, we dont have to add root
			if (root->left)
				result += pathSum(root->left, sum, false);
			if (root->right)
				result += pathSum(root->right, sum, false);
		}
		if (root->left)
			result += pathSum(root->left, sum - root->val, true);
		if (root->right)
			result += pathSum(root->right, sum - root->val, true);
		return result;
	}
	int pathSum(TreeNode* root, int sum) {
		// v1: faster than 79.29% 
		return pathSum(root, sum, false);
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

