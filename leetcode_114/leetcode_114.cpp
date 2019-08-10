// leetcode_114.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
/*
Given a binary tree, flatten it to a linked list in-place.
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
	TreeNode* doFlatten(TreeNode* root) {
		TreeNode* leftEnd = doFlatten(root->left);
		TreeNode* rightEnd = doFlatten(root->right);
		leftEnd->right = root->right;
		root->right = root->left;
		root->left = NULL;
		// todo
	}
	void flatten(TreeNode* root) {
		doFlatten(root);
	}
};
int main()
{
    std::cout << "Hello World!\n";
}