// N_ary_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
// n-ary tree

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class TrieNode {
public:
	shared_ptr<TrieNode> children[26];
	bool isEnd;
	TrieNode() {
		for (int i = 0; i < 26; ++i) {
			children[i] = shared_ptr<TrieNode>();
		}
		isEnd = false;
	}
};
class Trie {
	shared_ptr<TrieNode> root;
public:
	/** Initialize your data structure here. */
	Trie() {
		root = shared_ptr<TrieNode>(new TrieNode());
	}
	
	~Trie() {
		// Need not delete anything  
		// as shared_ptr deallocates  
		// all memory automatically 
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		shared_ptr<TrieNode> cur = root;
		for (char c : word) {
			if (cur->children[c - 'a'] == shared_ptr<TrieNode>(nullptr)) 
				cur->children[c - 'a'] = shared_ptr<TrieNode>(new TrieNode());
			cur = cur->children[c - 'a'];
		}
		cur->isEnd = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		shared_ptr<TrieNode> cur = root;
		for (char c : word) {
			if (cur->children[c - 'a'] == shared_ptr<TrieNode>(nullptr))
				return false;
			cur = cur->children[c - 'a'];
		}
		return cur->isEnd;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		shared_ptr<TrieNode> cur = root;
		for (char c : prefix) {
			if (cur->children[c - 'a'] == shared_ptr<TrieNode>(nullptr))
				return false;
			cur = cur->children[c - 'a'];
		}
		return true;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
