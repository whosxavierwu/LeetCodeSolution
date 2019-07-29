// leetcode_101.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/symmetric-tree/
/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Bonus points if you could solve it both recursively and iteratively.

*/
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool compare(TreeNode* leftRoot, TreeNode* rightRoot) {
		if ((leftRoot == NULL) ^ (rightRoot == NULL)) return false;
		if (leftRoot == NULL) return true;
		if (leftRoot->val != rightRoot->val) return false;
		return compare(leftRoot->left, rightRoot->right) & compare(leftRoot->right, rightRoot->left);
	}

	bool isSymmetric(TreeNode* root) {
		// v1: iterative  faster than 100.00% 
		//if (!root) return true;
		//if ((root->left == NULL) ^ (root->right == NULL))
		//	return false;
		//if (root->left == NULL)
		//	return true;
		//stack<TreeNode*> lsta;
		//stack<TreeNode*> rsta;
		//lsta.push(root->left);
		//rsta.push(root->right);
		//while (!lsta.empty() && !rsta.empty()) {
		//	TreeNode* ltmp = lsta.top();
		//	TreeNode* rtmp = rsta.top();
		//	if (ltmp->val != rtmp->val)
		//		return false;
		//	lsta.pop();
		//	rsta.pop();
		//	if ((ltmp->right == NULL) ^ (rtmp->left == NULL))
		//		return false;
		//	if (ltmp->right != NULL) {
		//		lsta.push(ltmp->right);
		//		rsta.push(rtmp->left);
		//	}
		//	if ((ltmp->left == NULL) ^ (rtmp->right == NULL))
		//		return false;
		//	if (ltmp->left != NULL) {
		//		lsta.push(ltmp->left);
		//		rsta.push(rtmp->right);
		//	}
		//}
		//return true;

		// v2: recursive faster than 55.78%
		if (root == NULL) return true;
		return compare(root->left, root->right);
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
