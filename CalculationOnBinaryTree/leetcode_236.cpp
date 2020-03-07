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

class Solution {
    //TreeNode* lca;
public:
    //bool recurseTree(TreeNode* cur, TreeNode* p, TreeNode* q) {
    //    if (cur == NULL)
    //        return false;
    //    int left = recurseTree(cur->left, p, q);
    //    int right = recurseTree(cur->right, p, q);
    //    int mid = (cur == p || cur == q);
    //    if (left + right + mid >= 2)
    //        lca = cur;
    //    return (left + right + mid > 0);
    //}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // v2  20 ms, faster than 76.21%
        stack<pair<TreeNode*, int>> sta;
        sta.push(make_pair(root, -1));
        bool found_one_node = false;
        TreeNode* lca = NULL;
        TreeNode* next = NULL;
        while (!sta.empty()) {
            pair<TreeNode*, int> top = sta.top();
            sta.pop();
            TreeNode* cur = top.first;
            int state = top.second;
            if (state == -1) {
                if (cur == p || cur == q) {
                    if (found_one_node)
                        return lca;
                    else {
                        found_one_node = true;
                        lca = cur;
                    }
                }
                sta.push(make_pair(cur, state + 1));
                if (cur->left != NULL)
                    sta.push(make_pair(cur->left, -1));
            }
            else if (state == 0) {
                sta.push(make_pair(cur, state + 1));
                if (cur->right != NULL)
                    sta.push(make_pair(cur->right, -1));
            }
            else {
                if (lca == cur && found_one_node) {
                    lca = sta.top().first;
                }
            }
        }
        return NULL;

        //// v1 36 ms, faster than 11.52% 
        //recurseTree(root, p, q);
        //return lca;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}
