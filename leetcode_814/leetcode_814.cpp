// leetcode_814.cpp : This file contains the 'main' function. Program execution begins and ends there.
// todo https://leetcode.com/problems/binary-tree-pruning/
/*
We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1.

Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

(Recall that the subtree of a node X is X, plus every node that is a descendant of X.)
*/

#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// v1: 4 ms, faster than 66.76%,  9.8 MB, less than 78.57%
class Solution {
public:
	TreeNode* pruneTree(TreeNode* root) {
		if (!root) return NULL;
		if (root->left) root->left = pruneTree(root->left);
		if (root->right) root->right = pruneTree(root->right);
		if (root->val == 0 && root->left == NULL && root->right == NULL) return NULL;
		return root;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
