// leetcode_106.cpp : This file contains the 'main' function. Program execution begins and ends there.
// todo https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

	}
};
int main()
{
    std::cout << "Hello World!\n";
}
