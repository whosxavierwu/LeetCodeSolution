// leetcode_965.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isUnivalTree(TreeNode* root, int& val) {
		if (!root) return true;
		return (root->val == val) && isUnivalTree(root->left, val) && isUnivalTree(root->right, val);
	}
	bool isUnivalTree(TreeNode* root) {
		// v1: faster than 100.00% 
		return isUnivalTree(root, root->val);
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

