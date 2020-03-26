// leetcode_700.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/search-in-a-binary-search-tree/

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		// v1: recursive, faster than 91%
		if (root == NULL)
			return NULL;
		TreeNode* cur = root;
		if (cur->val == val)
			return cur;
		else if (val < cur->val)
			return searchBST(cur->left, val);
		else
			return searchBST(cur->right, val);

		// v2: while; it's much slower, why???
		//TreeNode* cur = root;
		//while (cur) {
		//	if (cur->val == val)
		//		return cur;
		//	else if (val < cur->val)
		//		cur = cur->left;
		//	else
		//		cur = cur->right;
		//}
		//return NULL;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

