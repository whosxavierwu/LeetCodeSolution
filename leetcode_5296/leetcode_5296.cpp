// leetcode_5296.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-169/problems/all-elements-in-two-binary-search-trees/
/*
Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]
Example 3:

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]
Example 4:

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]
Example 5:


Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]


Constraints:

Each tree has at most 5000 nodes.
Each node's value is between [-10^5, 10^5].
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result;
        stack<TreeNode*> sta;
        if (root2 != NULL)
            sta.push(root2);
        if (root1 != NULL)
            sta.push(root1);
        while (!sta.empty()) {
            TreeNode* cur = sta.top();
            sta.pop();
            result.push_back(cur->val);
            if (cur->right != NULL)
                sta.push(cur->right);
            if (cur->left != NULL)
                sta.push(cur->left);
        }
        sort(result.begin(), result.end());
        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
