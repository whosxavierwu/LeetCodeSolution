// leetcode_226.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/invert-binary-tree/

#include <iostream>
#include <queue>
#include <deque>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		// v5: faster than 100.00% 
		if (!root) return root;
		TreeNode* tmp = invertTree(root->left);
		root->left = invertTree(root->right);
		root->right = tmp;
		return root;

		// v1: faster than 68.29% 
		if (root == NULL) return NULL;
		TreeNode* tmp = (root->left) ? invertTree(root->left) : NULL;
		root->left = (root->right) ? invertTree(root->right): NULL;
		root->right = tmp;
		return root;

		//// v2: faster than 8.37%
		//if (root) {
		//	invertTree(root->left);
		//	invertTree(root->right);
		//	swap(root->left, root->right);
		//}
		//return root;

		//// v3: faster than 68.29% 
		//if (root) {
		//	TreeNode* tmp = (root->left) ? invertTree(root->left) : NULL;
		//	root->left = (root->right) ? invertTree(root->right) : NULL;
		//	root->right = tmp;
		//}
		//return root;

		//// v4: faster than 68.29%
		//if (root == NULL) return NULL;
		//queue<TreeNode*> q;
		//q.push(root);
		//while (!q.empty()) {
		//	TreeNode* cur = q.front();
		//	q.pop();
		//	swap(cur->left, cur->right);
		//	if(cur->left)	
		//		q.push(cur->left);
		//	if(cur->right)
		//		q.push(cur->right);
		//}
		//return root;

		
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
