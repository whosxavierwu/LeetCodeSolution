// leetcode_94.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/binary-tree-inorder-traversal/
// Recursive solution is trivial, could you do it iteratively ?

#include <iostream>
#include <vector>
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
	vector<int> inorderTraversal(TreeNode* root) {
		// v1: recursive faster than 100.00%
		//vector<int> vec;
		//if (root) {
		//	if (root->left) {
		//		vec = inorderTraversal(root->left);
		//	}
		//	vec.push_back(root->val);
		//	if (root->right) {
		//		vector<int> tmp = inorderTraversal(root->right);
		//		vec.insert(vec.end(), tmp.begin(), tmp.end());
		//	}
		//}
		//return vec;

		// v2: iterative faster than 66.74%
		//stack<TreeNode*> sta;
		//vector<int> result;
		//TreeNode* tmp = root;
		//while (!sta.empty() || tmp != NULL) {
		//	while (tmp != NULL) {
		//		sta.push(tmp);
		//		tmp = tmp->left;
		//	}
		//	tmp = sta.top();
		//	sta.pop();
		//	result.push_back(tmp->val);
		//	tmp = tmp->right;
		//}
		//return result;

		// v3: Morris Traversal faster than 100.00% 
		vector<int> result;
		TreeNode* curRoot = root;
		TreeNode* prevRoot = NULL;
		while (curRoot) {
			if (curRoot->left == NULL) {
				result.push_back(curRoot->val);
				curRoot = curRoot->right;
			}
			else {
				// every time, we put cur to the rightmost of cur->left
				// so the right sub tree grows, when the left one becomes shorter
				prevRoot = curRoot->left;
				// find the rightmost
				while (prevRoot->right) {
					prevRoot = prevRoot->right;
				}
				prevRoot->right = curRoot; 
				TreeNode* tmp = curRoot;
				curRoot = curRoot->left;
				tmp->left = NULL;  // avoid loops
			}
		}
		return result;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
