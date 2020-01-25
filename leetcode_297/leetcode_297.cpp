// leetcode_297.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
/*
Design an algorithm to serialize and deserialize a binary tree. 
There is no restriction on how your serialization/deserialization algorithm should work. 
You just need to ensure that a binary tree can be serialized to a string 
and this string can be deserialized to the original tree structure.

You may serialize the following tree:

	1
   / \
  2   3
	 / \
	4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary tree. 
You do not necessarily need to follow this format, 
so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. 
Your serialize and deserialize algorithms should be stateless.
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
	// v1  88 ms, faster than 24.50%
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (root == NULL)
			return "#";
		return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data == "#")
			return NULL;
		stringstream ss(data);
		return doDeserialize(ss);
	}

	TreeNode* doDeserialize(stringstream& ss) {
		string str;
		getline(ss, str, ',');
		if (str == "#")
			return NULL;
		else {
			TreeNode* root = new TreeNode(stoi(str));
			root->left = doDeserialize(ss);
			root->right = doDeserialize(ss);
			return root;
		}
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
    std::cout << "Hello World!\n";
}
