// leetcode_106.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// v1: faster than 92.68% 
class Solution {
public:
	TreeNode* buildTree(const vector<int>& inorder, const vector<int>& postorder,
		pair<int, int> inStartEnd, pair<int, int> postStartEnd, 
		unordered_map<int, int>& mmap) {
		if (postStartEnd.first > postStartEnd.second || inStartEnd.first > inStartEnd.second)
			return NULL;
		int rootVal = postorder[postStartEnd.second];
		TreeNode* root = new TreeNode(rootVal);
		if (postStartEnd.first == postStartEnd.second) return root;
		int numOfRightNodes = inStartEnd.second - mmap[rootVal];
		int numOfLeftNodes = mmap[rootVal] - inStartEnd.first;
		root->left = buildTree(inorder, postorder,
			{ inStartEnd.first, mmap[rootVal] - 1 },
			{ postStartEnd.first, postStartEnd.first + numOfLeftNodes - 1 },
			mmap);
		root->right = buildTree(inorder, postorder,
			{ mmap[rootVal] + 1, inStartEnd.second },
			{ postStartEnd.second - numOfRightNodes, postStartEnd.second - 1 },
			mmap);
		return root;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		unordered_map<int, int> mmap;
		for (int i = 0; i < inorder.size(); ++i) 
			mmap[inorder[i]] = i;
		return buildTree(inorder, postorder, 
			{ 0, inorder.size() - 1 }, 
			{ 0, postorder.size() - 1 }, 
			mmap);
	}
};

//int main()
//{
//    std::cout << "Hello World!\n";
//}
