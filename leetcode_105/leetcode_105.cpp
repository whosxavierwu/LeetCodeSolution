// leetcode_105.cpp : This file contains the 'main' function. Program execution begins and ends there.
// todo https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

	3
   / \
  9  20
	/  \
   15   7
*/
#include <iostream>
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

	}
};
int main()
{
    std::cout << "Hello World!\n";
}
