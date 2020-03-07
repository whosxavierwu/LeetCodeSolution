// leetcode_236.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: 
The lowest common ancestor is defined between two nodes p and q 
as the lowest node in T 
that has both p and q as descendants (where we allow a node to be a descendant of itself).

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, 
since a node can be a descendant of itself according to the LCA definition.

Note:
All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.
*/

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// recursive version
class Solution {
    TreeNode* lca;
public:
    bool isInCurTree(TreeNode* cur, TreeNode* p, TreeNode* q) {
        if (cur == NULL) return false;
        bool isInLeft = isInCurTree(cur->left, p, q);
        bool isInRight = isInCurTree(cur->right, p, q);
        bool isCurNode = (cur == p || cur == q);
        if (isInLeft + isInRight + isCurNode >= 2)
            lca = cur;
        return isInLeft || isInRight || isCurNode;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        isInCurTree(root, p, q);
        return lca;
    }
};

// iterative version
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // v2  20 ms, faster than 76.21%
        stack<pair<TreeNode*, int>> sta;
        sta.push(make_pair(root, 0));
        bool foundOneNode = false;
        TreeNode* lca = NULL;
        while (!sta.empty()) {
            pair<TreeNode*, int> top = sta.top();
            sta.pop();
            TreeNode* cur = top.first;
            int timesOfVisited = top.second;
            if (timesOfVisited == 0) {
                if (cur == p || cur == q) {
                    if (foundOneNode)
                        return lca;
                    foundOneNode = true;
                    lca = cur;
                }
                sta.push(make_pair(cur, 1));
                if (cur->left != NULL)
                    sta.push(make_pair(cur->left, 0));
            }
            else if (timesOfVisited == 1) {
                // means all nodes in cur->left is visited
                sta.push(make_pair(cur, 2));
                if (cur->right != NULL)
                    sta.push(make_pair(cur->right, 0));
            }
            else {  // means cur->left & cur->right are visited
                if (lca == cur && foundOneNode)
                    lca = sta.top().first;
            }
        }
        return NULL;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}
