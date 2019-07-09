// leetcode_653.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// Given a Binary Search Tree and a target number, 
// return true if there exist two elements in the BST such that their sum is equal to the given target.

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

	bool findTarget(TreeNode* root, int k) {
		// COOL!!! it's faster than 99.35%!!!
		if (root == NULL)
			return false;
		stack<TreeNode*> s;
		TreeNode* cur;
		TreeNode* tmp;
		s.push(root);
		while (!s.empty()) {
			cur = s.top();
			tmp = searchBST(root, k - cur->val);
			if ((tmp != NULL) && (tmp != cur))
				return true;
			s.pop();
			if (cur->right)
				s.push(cur->right);
			if (cur->left)
				s.push(cur->left);
		}
		return false;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

