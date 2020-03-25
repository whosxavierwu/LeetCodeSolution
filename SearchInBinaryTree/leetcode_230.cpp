// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    void inorder(TreeNode* root, const int& k, int& curSmallest, int& result) {
        if (!root) return;
        inorder(root->left, k, curSmallest, result);
        curSmallest++;
        if (k == curSmallest) result = root->val;
        inorder(root->right, k, curSmallest, result);
    }
    int kthSmallest(TreeNode* root, int k) {
        int curSmallest = 0;
        int result = 0;
        inorder(root, k, curSmallest, result);
        return result;
    }
};
