// leetcode_1038.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
/*
Given the root of a binary search tree with distinct values, 
modify it so that every node has a new value 
equal to the sum of the values of the original tree that are greater than or equal to node.val.
*/
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode*> traverse(TreeNode *root) {
		vector<TreeNode*> vec;
		if (root == NULL) return vec;
		if (root->left != NULL)
			vec = traverse(root->left);
		vec.push_back(root);
		if (root->right != NULL) {
			vector<TreeNode*> vecR = traverse(root->right);
			vec.insert(vec.end(), vecR.begin(), vecR.end());
		}
		return vec;
	}
	TreeNode* bstToGst(TreeNode* root) {
		// v1 recursive faster than 100.00%
		vector<TreeNode*> nodes = traverse(root);
		for (int i = nodes.size() - 2; i >= 0; --i) {
			nodes[i]->val += nodes[i + 1]->val;
		}
		return root;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
