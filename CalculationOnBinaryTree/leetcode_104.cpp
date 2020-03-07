// leetcode_104.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		// v2: faster than 100.00% !!!
		return (root) ? fmax(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;

		// v1 recursive faster than 90.01% 
		if (root == NULL) return 0;
		int lDepth = (root->left != NULL) ? maxDepth(root->left) : 0;
		int rDepth = (root->right != NULL) ? maxDepth(root->right) : 0;
		return 1 + fmax(lDepth, rDepth);
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
