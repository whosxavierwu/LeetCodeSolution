// leetcode_559.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

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
	// v1: faster than 40.20% 
	void findMaxDepth(Node* node, int& max, int& cur) {
		if (!node) return;
		++cur;
		if (node->children.empty()) {
			if (cur > max)
				max = cur;
		}
		for (Node* child : node->children) {
			findMaxDepth(child, max, cur);
		}
		--cur;
	}
	int maxDepth(Node* root) {
		int max = 0, cur = 0;
		findMaxDepth(root, max, cur);
		return max;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}
