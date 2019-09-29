// leetcode_208.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/implement-trie-prefix-tree/
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
#include <memory>
using namespace std;


// v1: 140 ms, faster than 7.84%
//class TrieNode {
//public:
//	shared_ptr<TrieNode> children[26];
//	bool isEnd;
//	TrieNode() {
//		for (int i = 0; i < 26; ++i) {
//			children[i] = shared_ptr<TrieNode>();
//		}
//		isEnd = false;
//	}
//};
//class Trie {
//	shared_ptr<TrieNode> root;
//public:
//	/** Initialize your data structure here. */
//	Trie() {
//		root = shared_ptr<TrieNode>(new TrieNode());
//	}
//	
//	~Trie() {
//		// Need not delete anything  
//		// as shared_ptr deallocates  
//		// all memory automatically 
//	}
//
//	/** Inserts a word into the trie. */
//	void insert(string word) {
//		shared_ptr<TrieNode> cur = root;
//		for (char c : word) {
//			if (cur->children[c - 'a'] == shared_ptr<TrieNode>(nullptr)) 
//				cur->children[c - 'a'] = shared_ptr<TrieNode>(new TrieNode());
//			cur = cur->children[c - 'a'];
//		}
//		cur->isEnd = true;
//	}
//
//	/** Returns if the word is in the trie. */
//	bool search(string word) {
//		shared_ptr<TrieNode> cur = root;
//		for (char c : word) {
//			if (cur->children[c - 'a'] == shared_ptr<TrieNode>(nullptr))
//				return false;
//			cur = cur->children[c - 'a'];
//		}
//		return cur->isEnd;
//	}
//
//	/** Returns if there is any word in the trie that starts with the given prefix. */
//	bool startsWith(string prefix) {
//		shared_ptr<TrieNode> cur = root;
//		for (char c : prefix) {
//			if (cur->children[c - 'a'] == shared_ptr<TrieNode>(nullptr))
//				return false;
//			cur = cur->children[c - 'a'];
//		}
//		return true;
//	}
//};

// v2: 92 ms, faster than 33.40%
//class TrieNode {
//public:
//	TrieNode* children[26];
//	bool isEnd;
//	TrieNode() {
//		memset(children, 0, sizeof(children));
//		isEnd = false;
//	}
//};
//
//class Trie {
//private:
//	TrieNode* root;
//	void clear(TrieNode*cur) {
//		for (int i = 0; i < 26; ++i) {
//			if (cur->children[i] != nullptr) {
//				clear(cur->children[i]);
//			}
//		}
//		delete(cur);
//	}
//public:
//	Trie() {
//		root = new TrieNode();
//	}
//	~Trie() {
//		clear(root);
//	}
//	void insert(string word) {
//		TrieNode* cur = root;
//		for (char c : word) {
//			if (cur->children[c - 'a'] == nullptr) {
//				cur->children[c - 'a'] = new TrieNode();
//			}
//			cur = cur->children[c - 'a'];
//		}
//		cur->isEnd = true;
//	}
//	bool search(string word) {
//		TrieNode* cur = root;
//		for (char c : word) {
//			if (cur->children[c - 'a'] == nullptr) {
//				return false;
//			}
//			cur = cur->children[c - 'a'];
//		}
//		return cur->isEnd;
//	}
//	bool startsWith(string prefix) {
//		TrieNode* cur = root;
//		for (char c : prefix) {
//			if (cur->children[c - 'a'] == nullptr) {
//				return false;
//			}
//			cur = cur->children[c - 'a'];
//		}
//		return true;
//	}
//};


// v3: 64 ms, faster than 94.22%
class Trie {
private:
	Trie* children[26] = {};
	bool isEnd = false;
public:
	Trie() {}

	void insert(string word) {
		Trie* node = this;
		for (char c : word) {
			int idx = c - 'a';
			if (node->children[idx] == nullptr)
				node->children[idx] = new Trie();
			node = node->children[idx];
		}
		node->isEnd = true;
	}

	bool search(string word) {
		Trie* node = this;
		for (char c : word) {
			int idx = c - 'a';
			if (node->children[idx] == nullptr)
				return false;
			node = node->children[idx];
		}
		return node->isEnd;
	}

	bool startsWith(string prefix) {
		Trie* node = this;
		for (char c : prefix) {
			int idx = c - 'a';
			if (node->children[idx] == nullptr)
				return false;
			node = node->children[idx];
		}
		return true;
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
