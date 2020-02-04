// leetcode_102.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		// v1: faster than 93.84% 
		if (!root) return {};
		deque<TreeNode*> deq;
		deq.push_back(root);
		vector<vector<int>> result;
		while (!deq.empty()) {
			vector<int> s;
			int len = deq.size();
			for (int i = 0; i < len; ++i) {
				s.push_back(deq.front()->val);
				if (deq.front()->left)
					deq.push_back(deq.front()->left);
				if (deq.front()->right)
					deq.push_back(deq.front()->right);
				deq.pop_front();
			}
			result.push_back(s);
		}
		return result;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}

