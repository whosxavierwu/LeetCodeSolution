// leetcode_543.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/diameter-of-binary-tree/
/*
Given a binary tree, you need to compute the length of the diameter of the tree. 
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

The length of path between two nodes is represented by the number of edges between them.

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
	//int maxDepth(TreeNode* root) {
	//	return root ? fmax(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
	//}

	int maxDepth(TreeNode* root, int &maxDiameter) {
		if (!root) return 0;
		int lDepth = maxDepth(root->left, maxDiameter);
		int rDepth = maxDepth(root->right, maxDiameter);
		int diameter = lDepth + rDepth;
		if (diameter > maxDiameter)
			maxDiameter = diameter;
		return fmax(lDepth, rDepth) + 1;
	}

	int diameterOfBinaryTree(TreeNode* root) {
		// v2 faster than 74.11% 
		if (!root) return 0;
		int result = 0;
		int depth = maxDepth(root, result);
		return result;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

