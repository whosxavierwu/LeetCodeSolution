// leetcode_5052.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level X such that the sum of all the values of nodes at level X is maximal.
*/
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxLevelSum(TreeNode* root) {
		queue<pair<TreeNode*, int>> q;
		unordered_map<int, int> levelCntMap;
		q.push({ root, 1 });
		while (!q.empty()) {
			pair<TreeNode*, int> cur = q.front();
			q.pop();
			TreeNode* curNode = cur.first;
			int curDepth = cur.second;
			levelCntMap[curDepth] += curNode->val;
			if (curNode->left != NULL)
				q.push({ curNode->left, curDepth + 1 });
			if (curNode->right != NULL)
				q.push({ curNode->right, curDepth + 1 });
		}
		int level = 0;
		int maxsum = INT_MIN;
		for (auto iter = levelCntMap.begin(); iter != levelCntMap.end(); ++iter) {
			if (iter->second > maxsum) {
				maxsum = iter->second;
				level = iter->first;
			}
		}
		return level;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
