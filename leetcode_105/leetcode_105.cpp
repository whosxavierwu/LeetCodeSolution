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
#include <unordered_map>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//v1: TLE
//class Solution {
//public:
//	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, 
//		unordered_map<int, int> mmap, 
//		pair<int, int> preStartEnd, pair<int, int> inStartEnd) {
//		if (preStartEnd.first > preStartEnd.second) return NULL;
//		TreeNode* root = new TreeNode(preorder[preStartEnd.first]);
//		if (preStartEnd.first == preStartEnd.second) return root;
//		if (preStartEnd.first + 1 == preStartEnd.second) {
//			TreeNode* tmp = new TreeNode(preorder[preStartEnd.second]);
//			if (inorder[inStartEnd.first] == preorder[preStartEnd.first])
//				root->right = tmp;
//			else
//				root->left = tmp;
//			return root;
//		}
//		int rootIdxAtInorder = mmap[preorder[preStartEnd.first]];
//		int rightIdx = preStartEnd.first + 1;
//		while (rightIdx <= preStartEnd.second && mmap[preorder[rightIdx]] <= rootIdxAtInorder)
//			++rightIdx;
//		root->left = buildTree(preorder, inorder, mmap, { preStartEnd.first + 1, rightIdx - 1 }, { inStartEnd.first, rootIdxAtInorder - 1 });
//		root->right = buildTree(preorder, inorder, mmap, { rightIdx, preStartEnd.second }, { rootIdxAtInorder + 1, inStartEnd.second });
//		return root;
//	}
//	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//		unordered_map<int, int> mmap;
//		for (int i = 0; i < inorder.size(); ++i)
//			mmap[inorder[i]] = i;
//		return buildTree(preorder, inorder, mmap, 
//			{ 0, preorder.size() - 1 }, { 0, inorder.size() - 1 });
//	}
//};

//v2: faster than 5.34%, less than 95.24%
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int len = preorder.size();
		if (len == 0) return NULL;
		if (len == 1) return new TreeNode(preorder.back());
		unordered_map<int, int> mmap;
		for (int i = 0; i < len; ++i)
			mmap[inorder[i]] = i;
		vector<TreeNode*> vec(len, NULL);
		vec[0] = new TreeNode(preorder[0]);
		for (int i = 0; i < len - 1; ++i) {
			int leftIdx = i;
			for (int j = i + 1; j < len && vec[j] == NULL; ++j) {
				if (mmap[preorder[j]] < mmap[preorder[i]]) {
					vec[j] = new TreeNode(preorder[j]);
					vec[i]->left = vec[j];
					leftIdx = j;
					break;
				}
			}
			for (int j = leftIdx + 1; j < len && vec[j] == NULL; ++j) {
				if (mmap[preorder[i]] < mmap[preorder[j]]) {
					vec[j] = new TreeNode(preorder[j]);
					vec[i]->right = vec[j];
					break;
				}
			}
		}
		return vec[0];
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
