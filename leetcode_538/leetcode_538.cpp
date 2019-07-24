// leetcode_538.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/convert-bst-to-greater-tree/

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
	int sum = 0;
public:
	//vector<TreeNode*> traverse(TreeNode* root) {
	//	vector<TreeNode*> vec;
	//	if (root == NULL) return vec;
	//	if (root->left != NULL)
	//		vec = traverse(root->left);
	//	vec.push_back(root);
	//	if (root->right != NULL) {
	//		vector<TreeNode*> vecR = traverse(root->right);
	//		vec.insert(vec.end(), vecR.begin(), vecR.end());
	//	}
	//	return vec;
	//}
	TreeNode* convertBST(TreeNode* root) {
		//// v1: faster than 7.69% 
		//vector<TreeNode*> nodes = traverse(root);
		//for (int i = nodes.size() - 2; i >= 0; --i) {
		//	nodes[i]->val += nodes[i + 1]->val;
		//}
		//return root;

		// v2: faster than 25.82%
		//if (root) {
		//	convertBST(root->right);
		//	root->val += sum;
		//	sum = root->val;
		//	convertBST(root->left);
		//}
		//return root;

		// v3: faster than 7.69% 
		TreeNode* p = root;
		int sum = 0;
		stack<TreeNode*> sta;
		while (!sta.empty() || p != NULL) {
			while (p != NULL) {
				sta.push(p);
				p = p->right;
			}
			p = sta.top();
			sta.pop();
			sum += p->val;
			p->val = sum;
			p = p->left;
		}
		return root;
	}
};

// v4  faster than 74.22%
class Solution {
public:
	int traverse(TreeNode* node, int sum) {
		if (!node) return sum;
		node->val += traverse(node->right, sum);
		return traverse(node->left, node->val);
	}

	TreeNode* convertBST(TreeNode* root) {
		if (!root) return root;
		root->val += traverse(root->right, 0);
		traverse(root->left, root->val);
		return root;
	}
};



int main()
{
    std::cout << "Hello World!\n";
}
