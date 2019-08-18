// leetcode_897.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//v1 faster than 97.06%
class Solution {
public:
	pair<TreeNode*, TreeNode*> func(TreeNode* root) {
		pair<TreeNode*, TreeNode*> result = { root, root };
		if(root->left != NULL) {
			auto pLeft = func(root->left);
			pLeft.second->right = root;
			root->left = NULL;
			result.first = pLeft.first;
		}
		if (root->right != NULL) {
			auto pRight = func(root->right);
			result.second = pRight.second;
			root->right = pRight.first;
		}		
		return result;
	}
	TreeNode* increasingBST(TreeNode* root) {
		if (!root) return root;
		auto p = func(root);
		return p.first;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
