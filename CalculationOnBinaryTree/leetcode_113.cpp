// leetcode_113.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/path-sum-ii/

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
	//void pathSum(TreeNode* root, int sum, vector<vector<int>>& result, vector<int> cur) {
	//	if (!root) return;
	//	cur.push_back(root->val);
	//	if (root->left == NULL && root->right == NULL) {
	//		if (root->val == sum)
	//			result.push_back(cur);
	//	}
	//	else {
	//		if (root->left) 
	//			pathSum(root->left, sum - root->val, result, cur);
	//		if (root->right) 
	//			pathSum(root->right, sum - root->val, result, cur);
	//	} 
	//}
	void findPaths(TreeNode *root, int sum, vector<int>& path, vector<vector<int>>& result) {
		if (!root) return;
		path.push_back(root->val);
		if (root->left == NULL && root->right == NULL && root->val == sum)
			result.push_back(path);
		findPaths(root->left, sum - root->val, path, result);
		findPaths(root->right, sum - root->val, path, result);
		path.pop_back();
	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		// v2 faster than 71.36%
		vector<vector<int>> result;
		vector<int> cur;
		findPaths(root, sum, cur, result);
		return result;

		//// v1: faster than 33.32%
		//vector<vector<int>> result;
		//vector<int> cur;
		//pathSum(root, sum, result, cur);
		//return result;

		
	}
};
int main()
{
    std::cout << "Hello World!\n";
}
