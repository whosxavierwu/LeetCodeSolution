// leetcode_112.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/path-sum/
/*
Given a binary tree and a sum, 
determine if the tree has a root-to-leaf path such 
that adding up all the values along the path equals the given sum.
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
	bool hasPathSum(TreeNode* root, int sum) {
		// v1: faster than 50.91% 
		if (!root) return false;
		if (root->left == NULL && root->right == NULL)
			return root->val == sum;
		return hasPathSum(root->left, sum - root->val) 
			| hasPathSum(root->right, sum - root->val);
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
