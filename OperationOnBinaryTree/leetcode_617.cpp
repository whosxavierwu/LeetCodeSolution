// leetcode_617.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/merge-two-binary-trees/
// Given two binary trees and imagine that when you put one of them to cover the other, 
// some nodes of the two trees are overlapped while the others are not.
// You need to merge them into a new binary tree.
// The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node.
// Otherwise, the NOT null node will be used as the node of new tree.
// Note: The merging process must start from the root nodes of both trees.

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		// v1: Recursion, faster than 72%
		if (t1 == NULL)
			return t2;
		if (t2 == NULL)
			return t1;
		TreeNode* head = new TreeNode(t1->val + t2->val);
		head->left = mergeTrees(t1->left, t2->left);
		head->right = mergeTrees(t1->right, t2->right);
		return head;
		// v2: iterative? use stack; how ???
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

