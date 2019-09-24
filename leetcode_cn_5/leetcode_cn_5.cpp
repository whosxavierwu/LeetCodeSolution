// leetcode_cn_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode-cn.com/contest/season/2019-fall/problems/coin-bonus/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
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
public:
	vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
		vector<int> countOfChildren(n + 1, 0);
		for (vector<int> relation : leadership)
			countOfChildren[relation[0]] += 1;
		vector<Node*> nodes;
		nodes.push_back(new Node());
		for (int i = 1; i <= n; ++i) {
			nodes.push_back(new Node(0, vector<Node*>(countOfChildren[i])));
		}
		vector<int> idxs(n + 1, 0);
		for (vector<int> relation : leadership) {
			//nodes[relation[0]]->children.push_back(nodes[relation[1]]);
			nodes[relation[0]]->children[idxs[relation[0]]] = nodes[relation[1]];
			idxs[relation[0]] += 1;
		}
			
		vector<int> result;
		for (vector<int> operation : operations) {
			int idx = operation[1];
			if (operation[0] == 1) {
				nodes[idx]->val = (nodes[idx]->val + operation[2]) % 1000000007;
			}
			else if (operation[0] == 2) {
				nodes[idx]->val = (nodes[idx]->val + operation[2]) % 1000000007;
				for (Node*& child : nodes[idx]->children)
					child->val = (child->val + operation[2]) % 1000000007;
			}
			else {
				int sum = nodes[idx]->val;
				for (Node*& child : nodes[idx]->children)
					sum = (sum + child->val) % 1000000007;
				result.push_back(sum);
			}
		}
		return result;
	}
};
int main()
{
	Solution sol;
	int N = 6;
	vector<vector<int>> leadership = { {1, 2} ,{1, 6},{2, 3},{2, 5},{1, 4} };
	vector<vector<int>> operations = { {1, 1, 500} ,{2, 2, 50},{3, 1},{2, 6, 15},{3, 1} };
	vector<int> result = sol.bonus(N, leadership, operations);
	for (int a : result)
		cout << a << " ";
	cout << endl;
}
