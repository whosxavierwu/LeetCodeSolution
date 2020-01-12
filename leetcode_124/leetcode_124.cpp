// leetcode_124.cpp : This file contains the 'main' function. Program execution begins and ends there.
// todo https://leetcode.com/problems/binary-tree-maximum-path-sum/
/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, 
a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42

*/
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
    int maxPathSum(TreeNode* root) {

    }
};

int main()
{
    std::cout << "Hello World!\n";
}
