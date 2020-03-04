// leetcode_146.cpp 
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


class LRUCache {
	unordered_map<int, pair<int, list<int>::iterator>> cache;  // key: (value, iter)
	list<int> keyUsedLog;  // from latest to oldest
	int maxSize;

	void touch(unordered_map<int, pair<int, list<int>::iterator>>::iterator cacheIter) {
		int key = cacheIter->first;
		auto logIter = cacheIter->second.second;
		keyUsedLog.erase(logIter);
		keyUsedLog.push_front(key);
		cacheIter->second.second = keyUsedLog.begin();
	}
public:
	LRUCache(int capacity) : maxSize(capacity) {}

	int get(int key) {
		auto cacheIter = cache.find(key);
		if (cacheIter == cache.end()) 
			return -1;
		touch(cacheIter);
		int value = cacheIter->second.first;
		return value;
	}

	void put(int key, int value) {
		auto cacheIter = cache.find(key);
		if (cacheIter != cache.end()) 
			touch(cacheIter);
		else {
			if (cache.size() == maxSize) {
				cache.erase(keyUsedLog.back());
				keyUsedLog.pop_back();
			}
			keyUsedLog.push_front(key);
		}
		cache[key] = { value, keyUsedLog.begin() };
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
