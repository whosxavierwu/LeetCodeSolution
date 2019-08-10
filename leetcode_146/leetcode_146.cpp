// leetcode_146.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/lru-cache/
/*
Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key 
if the key exists in the cache, otherwise return -1.

put(key, value) - Set or insert the value if the key is not already present. 
When the cache reached its capacity, 
it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?
*/
#include <iostream>
#include <unordered_map>
using namespace std;

// v1: faster than 54.14% 
class LRUCache {
	// key: (value, iter)
	unordered_map<int, pair<int, list<int>::iterator>> cache;
	list<int> used;
	int availCapacity;
	void touch(unordered_map<int, pair<int, list<int>::iterator>>::iterator iter) {
		int key = iter->first;
		used.erase(iter->second.second);
		used.push_front(key);
		iter->second.second = used.begin();
	}
public:
	LRUCache(int capacity): availCapacity(capacity) {
	}

	int get(int key) {
		auto it = cache.find(key);
		if (it == cache.end()) return -1;
		touch(it);
		return it->second.first;
	}

	void put(int key, int value) {
		auto iter = cache.find(key);
		if (iter != cache.end()) touch(iter);
		else {
			if (cache.size() == availCapacity) {
				cache.erase(used.back());
				used.pop_back();
			}
			used.push_front(key);
		}
		cache[key] = { value, used.begin() };
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{
    std::cout << "Hello World!\n";
}
