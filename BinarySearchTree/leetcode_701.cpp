// leetcode_701.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/insert-into-a-binary-search-tree/
/*
Given the root node of a binary search tree (BST) and a value to be inserted into the tree, 
insert the value into the BST. 
Return the root node of the BST after the insertion. 
It is guaranteed that the new value does not exist in the original BST.

Note that there may exist multiple valid ways for the insertion, 
as long as the tree remains a BST after insertion. 
You can return any of them.
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
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		// v3: faster than 73.03% 
		if (root == NULL)
			return new TreeNode(val);
		if (val < root->val)
			root->left = insertIntoBST(root->left, val);
		else
			root->right = insertIntoBST(root->right, val);
		return root;

		// v4: faster than 73.03%
		TreeNode** cur = &root;
		while (*cur)
			cur = (val > (*cur)->val) ? &(*cur)->right : &(*cur)->left;
		*cur = new TreeNode(val);
		return root;

		//// v1: recursive faster than 10.87% 
		//TreeNode* tmp = new TreeNode(val);
		//if (val < root->val) {
		//	if (root->left == NULL)
		//		root->left = new TreeNode(val);
		//	else
		//		insertIntoBST(root->left, val);
		//}
		//else {
		//	if (root->right == NULL)
		//		root->right = new TreeNode(val);
		//	else
		//		insertIntoBST(root->right, val);
		//}
		//return root;

		//// v2 faster than 53.23%
		//TreeNode* cur = root;
		//TreeNode* tmp = new TreeNode(val);
		//while (cur) {
		//	if (val < cur->val) {
		//		if (cur->left) {
		//			cur = cur->left;
		//		}
		//		else {
		//			cur->left = tmp;
		//			break;
		//		}
		//	}
		//	else {
		//		if (cur->right) {
		//			cur = cur->right;
		//		}
		//		else {
		//			cur->right = tmp;
		//			break;
		//		}
		//	}
		//}
		//return root;

		

		

		
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
