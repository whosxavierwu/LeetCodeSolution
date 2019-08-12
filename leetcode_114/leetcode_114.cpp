// leetcode_114.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
/*
Given a binary tree, flatten it to a linked list in-place.
*/

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* func(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* lend = root;
        TreeNode* rend = root;
        if (root->left && root->right) {
            lend = func(root->left);
            rend = func(root->right);
            lend->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        else if (root->left) {
            lend = func(root->left);
            root->right = root->left;
            root->left = NULL;
            rend = lend;
        }
        else if (root->right) {
            rend = func(root->right);
        }
        else {
            rend = root;
        }

        return rend;
    }
    void flatten(TreeNode* root) {
        func(root);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
