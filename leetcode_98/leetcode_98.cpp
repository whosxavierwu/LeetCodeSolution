// leetcode_98.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/validate-binary-search-tree/
/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:

	2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

	5
   / \
  1   4
	 / \
	3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
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

// v1: faster than 63.02%
//class Solution {
//public:
//	bool isValidBST(TreeNode* root, long low, long high) {
//		if (root == NULL) return true;
//		if (root->val <= low || root->val >= high) return false;
//		if (root->left != NULL && root->left->val >= root->val) return false;
//		if (root->right != NULL && root->val >= root->right->val) return false;
//		return ((root->left == NULL) || isValidBST(root->left, low, root->val))
//			&& ((root->right == NULL) || isValidBST(root->right, root->val, high));
//	}
//	bool isValidBST(TreeNode* root) { 
//		return isValidBST(root, LONG_MIN, LONG_MAX);
//	}
//};

// v2: faster than 63.02%
//class Solution {
//public:
//	bool isValidBST(TreeNode* root, pair<long, long> bound) {
//		if (root == NULL) return true;
//		if (root->val <= bound.first || root->val >= bound.second) return false;
//		if (root->left != NULL && root->left->val >= root->val) return false;
//		if (root->right != NULL && root->val >= root->right->val) return false;
//		if (!isValidBST(root->left, { bound.first, root->val })) return false;
//		if (!isValidBST(root->right, { root->val, bound.second })) return false;
//		return true;
//	}
//	bool isValidBST(TreeNode* root) {
//		return isValidBST(root, { LONG_MIN, LONG_MAX });
//	}
//};

// v3: faster than 98.50%, less than 97.92% 
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (!root) return true;
		stack<pair<TreeNode*, pair<long, long>>> sta;
		sta.push({ root, {LONG_MIN, LONG_MAX} });
		while (!sta.empty()) {
			pair<TreeNode*, pair<long, long>> cur = sta.top();
			sta.pop();
			TreeNode* root = cur.first;
			long low = cur.second.first;
			long high = cur.second.second;
			if (root->val <= low || root->val >= high) return false;
			if (root->right != NULL) {
				if (root->val >= root->right->val) return false;
				sta.push({ root->right, {root->val, high} });
			}
			if (root->left != NULL) {
				if (root->left->val >= root->val) return false;
				sta.push({ root->left, {low, root->val} });
			}
		}
		return true;
	}
};

int main()
{
	Solution sol; 
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	bool result = sol.isValidBST(root);
	cout << result << endl;
}
