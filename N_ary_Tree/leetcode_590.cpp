// leetcode_590.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/n-ary-tree-postorder-traversal/
// Recursive solution is trivial, could you do it iteratively?

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
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
	vector<int> postorder(Node* root) {
		// iterative: faster than 72.56% 
		vector<int> result;
		if (root == NULL) return result;
		stack<Node*> sta;
		sta.push(root);
		while (!sta.empty()) {
			Node* tmp = sta.top();
			sta.pop();
			for (Node* child : tmp->children)
				sta.push(child);
			result.push_back(tmp->val);
		}
		reverse(result.begin(), result.end());
		return result;

		//// recursive: faster than 27.97%
		//vector<int> result; 
		//if (root == NULL) return result;
		//for (Node* child : root->children) {
		//	vector<int> tmp = postorder(child);
		//	result.insert(result.end(), tmp.begin(), tmp.end());
		//}
		//result.push_back(root->val);
		//return result;

		// iterative v2: faster than 72.56% too...
		//vector<int> result;
		//if (root == NULL) return result;
		//stack<Node*> sta;
		//deque<int> q;
		//sta.push(root);
		//while (!sta.empty()) {
		//	Node* tmp = sta.top();
		//	sta.pop();
		//	for (Node* child : tmp->children)
		//		sta.push(child);
		//	q.push_front(tmp->val);
		//}
		//result.insert(result.end(), q.begin(), q.end());
		//return result;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

