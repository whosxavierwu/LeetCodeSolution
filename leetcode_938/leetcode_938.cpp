// leetcode_938.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	int rangeSumBST(TreeNode* root, int L, int R) {
		// v1: faster than 86.44%
		if (root == NULL)
			return 0;

		if (root->val < L)
			return rangeSumBST(root->right, L, R);
		else if (root->val > R)
			return rangeSumBST(root->left, L, R);
		else {
			return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
		}
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
