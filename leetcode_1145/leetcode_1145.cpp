// leetcode_1145.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// faster than 100.00%
	TreeNode* findNode(TreeNode* root, const int& x) {
		if (!root) return NULL;
		if (root->val == x) return root;
		TreeNode* target = findNode(root->left, x);
		if (target) return target;
		return findNode(root->right, x);
	}
	int countTree(TreeNode* root) {
		if (!root) return 0;
		int result = 1;
		if (root->left) result += countTree(root->left);
		if (root->right) result += countTree(root->right);
		return result;
	}
	bool btreeGameWinningMove(TreeNode* root, int n, int x) {
		TreeNode* nodex = findNode(root, x);
		int left = countTree(nodex->left);
		int right = countTree(nodex->right);
		int other = n - left - right - 1;
		int pick = fmax(fmax(left, right), other);
		return pick > (n - pick);
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

