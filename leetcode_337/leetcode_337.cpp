// leetcode_337.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/house-robber-iii/

#include <iostream>
#include <stack>
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
	//int rob(TreeNode* root, bool isRobbing) {
	//	if (!root) return 0;
	//	int result = 0;
	//	if (isRobbing) {
	//		result = root->val;
	//		if (root->left)
	//			result += rob(root->left, false);
	//		if (root->right)
	//			result += rob(root->right, false);
	//	}
	//	else {
	//		if (root->left)
	//			result += fmax(rob(root->left, false), rob(root->left, true));
	//		if (root->right)
	//			result += fmax(rob(root->right, false), rob(root->right, true));
	//	}
	//	return result;
	//}
	pair<int, int> robFunc(TreeNode* root) {
		if (!root) return { 0,0 };
		pair<int, int> left = robFunc(root->left);
		pair<int, int> right = robFunc(root->right);
		pair<int, int> result;
		result.first = fmax(left.first, left.second) + fmax(right.first, right.second);
		result.second = root->val + left.first + right.first;
		return result;
	}
	int rob(TreeNode* root) {
		// v1: faster than 5.06% 
		//int result = 0;
		//result = fmax(rob(root, false), rob(root, true));
		//return result;

		// v2 faster than 5.06%
		//if (!root) return 0;
		//int result = 0;
		//if (root->left)
		//	result += rob(root->left->left) + rob(root->left->right);
		//if (root->right)
		//	result += rob(root->right->left) + rob(root->right->right);
		//return fmax(root->val + result, rob(root->left) + rob(root->right));

		// v3 faster than 95.25% 
		pair<int, int> result = robFunc(root);
		return fmax(result.first, result.second);
	}
};
int main()
{
    std::cout << "Hello World!\n";
}
