// leetcode_208.cpp : This file contains the 'main' function. Program execution begins and ends there.
// todo https://leetcode.com/problems/implement-trie-prefix-tree/
/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Trie {
	struct TreeNode {
		char val;
		vector<TreeNode*> children;
		bool isEnd;
		TreeNode(char x): val(x), children(vector<TreeNode*>()), isEnd(false) {}
	};
	vector<TreeNode*> roots;
public:
	/** Initialize your data structure here. */
	Trie() {
		roots = vector<TreeNode*>(26);
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {

	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {

	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
    std::cout << "Hello World!\n";
}
