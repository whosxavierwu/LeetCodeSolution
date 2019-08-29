// leetcode_1008.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
/*
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, 
any descendant of node.left has a value < node.val, 
and any descendant of node.right has a value > node.val.  
Also recall that a preorder traversal 
displays the value of the node first, then traverses node.left, then traverses node.right.)

1 <= preorder.length <= 100
The values of preorder are distinct.
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
	// v1: 4 ms, faster than 83.21%,  9 MB, less than 100.00% 
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		int len = preorder.size();
		if (len == 0) return NULL;
		vector<TreeNode*> vec;
		vector<bool> marked(len, false);
		for (int v : preorder)
			vec.push_back(new TreeNode(v));
		marked[0] = true;
		for (int i = 0; i < len-1; ++i) {
			int rightStart = i + 1;
			while (rightStart < len && preorder[rightStart] < preorder[i] && !marked[rightStart])
				++rightStart;
			if (rightStart > i + 1 && !marked[i+1]) {
				vec[i]->left = vec[i + 1];
				marked[i + 1] = true;
			}
			if (rightStart < len && !marked[rightStart]) {
				vec[i]->right = vec[rightStart];
				marked[rightStart] = true;
			}
		}
		return vec[0];
	}
};
int main()
{
	Solution sol;
	vector<int> preorder = { 8,5,1,7,10,12 };
	TreeNode* root = sol.bstFromPreorder(preorder);
}
