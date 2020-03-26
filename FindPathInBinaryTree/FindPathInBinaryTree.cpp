// FindPathInBinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

// https://leetcode.com/problems/path-sum/
bool hasRoot2LeafPathSum(TreeNode* root, int sum) {
    if (root == NULL) 
        return false;
    // root-to-leaf path
    if (root->left == NULL && root->right == NULL && root->val == sum) 
        return true;
    if (root->left != NULL && hasRoot2LeafPathSum(root->left, sum - root->val))
        return true;
    if (root->right != NULL && hasRoot2LeafPathSum(root->right, sum - root->val))
        return true;
    return false;
}

// https://leetcode.com/problems/path-sum-ii/
void findRoot2LeafPathSum(TreeNode* root, int target, vector<int>& curPath, vector<vector<int>>& allPaths) {
    if (root == NULL)
        return;
    curPath.push_back(root->val);
    // root-to-leaf path
    if (root->left == NULL && root->right == NULL && root->val == target)
        allPaths.push_back(curPath);
    findRoot2LeafPathSum(root->left, target - root->val, curPath, allPaths);
    findRoot2LeafPathSum(root->right, target - root->val, curPath, allPaths);
    curPath.pop_back();
}
vector<vector<int>> findRoot2LeafPathSum(TreeNode *root, int sum) {
    vector<vector<int>> allPaths;
    vector<int> curPath;
    findRoot2LeafPathSum(root, sum, curPath, allPaths);
    return allPaths;
}

// https://leetcode.com/problems/path-sum-iii/
int findAllPathSum(TreeNode* root, int sum, bool isPathHead) {
    if (root == NULL) return 0;
    int count = (sum == root->val);
    if (!isPathHead) {
        count += findAllPathSum(root->left, sum, false);
        count += findAllPathSum(root->right, sum, false);
    }
    count += findAllPathSum(root->left, sum - root->val, true);
    count += findAllPathSum(root->right, sum - root->val, true);
    return count;
}
int findAllPathSum(TreeNode* root, int sum) {
    return findAllPathSum(root, sum, false);
}

// https://leetcode.com/problems/binary-tree-paths/
vector<string> findRoot2LeafPaths(TreeNode* root) {
    if (root == NULL)
        return {};
    if (root->left == NULL && root->right == NULL)
        return { to_string(root->val) };
    vector<string> result = findRoot2LeafPaths(root->left);
    vector<string> right = findRoot2LeafPaths(root->right);
    result.insert(result.end(), right.begin(), right.end());
    int n = result.size();
    for (int i = 0; i < n; ++i)
        result[i] = to_string(root->val) + "->" + result[i];
    return result;
}

// https://leetcode.com/problems/binary-tree-maximum-path-sum/
int maxDownRouteSum(TreeNode* root, int& maxValue) {
    if (root == NULL) return 0;
    int left = max(0, maxDownRouteSum(root->left, maxValue));
    int right = max(0, maxDownRouteSum(root->right, maxValue));
    maxValue = max(maxValue, left + right + root->val);
    return max(left, right) + root->val;
}
int maxRouteSum(TreeNode* root) {
    if (root == NULL) return 0;
    int maxValue = root->val;
    maxDownRouteSum(root, maxValue);
    return maxValue;
}

//  https://leetcode.com/problems/sum-root-to-leaf-numbers/
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        stack<pair<TreeNode*, int>> sta;
        sta.push({ root, 0 });
        int result = 0;
        while (!sta.empty()) {
            TreeNode* cur = sta.top().first;
            int prevSum = sta.top().second;
            sta.pop();
            if (cur->left || cur->right) {
                if (cur->left)
                    sta.push({ cur->left, 10 * prevSum + cur->val });
                if (cur->right)
                    sta.push({ cur->right, 10 * prevSum + cur->val });
            }
            else {
                result += 10 * prevSum + cur->val;
            }
        }
        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
