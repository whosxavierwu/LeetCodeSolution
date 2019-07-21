// leetcode_589.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/n-ary-tree-preorder-traversal/
// Recursive solution is trivial, could you do it iteratively?

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	vector<int> preorder(Node* root) {
		//// recursive: faster than 23.46% 
		//vector<int> result;
		//if (root == NULL) return result;
		//result.push_back(root->val);
		//for (Node* child : root->children) {
		//	vector<int> tmp = preorder(child);
		//	result.insert(result.end(), tmp.begin(), tmp.end());
		//}
		//return result;

		// iterative: faster than 96.73%
		vector<int> result;
		if (root == NULL) return result;
		stack<Node*> sta;
		sta.push(root);
		while (!sta.empty()) {
			Node* tmp = sta.top();
			result.push_back(tmp->val);
			sta.pop();
			for (int i = tmp->children.size() - 1; i >= 0; --i)
				sta.push(tmp->children[i]);
		}
		return result;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

