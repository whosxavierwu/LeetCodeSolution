// Cache.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <cstdio>
using namespace std;

// https://leetcode.com/problems/lru-cache/
class LRUCache {
    list<int> keyUsedLog;
    unordered_map<int, pair<int, list<int>::iterator>> cache;  // key: (value, logIter)
    int maxSize;
    void touch(unordered_map<int, pair<int, list<int>::iterator>>::iterator cacheIter) {
        int key = cacheIter->first;
        auto logIter = cacheIter->second.second;
        keyUsedLog.erase(logIter);
        keyUsedLog.push_front(key);
        cacheIter->second.second = keyUsedLog.begin();
    }
public:
    LRUCache(int capacity) {
        maxSize = capacity;
    }
    int get(int key) {
        auto cacheIter = cache.find(key);
        if (cacheIter == cache.end())
            return -1;
        touch(cacheIter);
        return cacheIter->second.first;
    }
    void put(int key, int value) {
        if (maxSize == 0) return;
        auto cacheIter = cache.find(key);
        if (cacheIter != cache.end()) {
            touch(cacheIter);
        }
        else {
            if (keyUsedLog.size() >= maxSize) {
                cache.erase(keyUsedLog.back());
                keyUsedLog.pop_back();
            }
            keyUsedLog.push_front(key);
        }
        cache[key] = { value, keyUsedLog.begin() };
    }
};

int main()
{
    char action;
    int capacity, key, value;
    cin >> capacity;
    LRUCache lru = LRUCache(capacity);
    while (cin >> action) {
        if (action == 'p') {
            cin >> key >> value;
            lru.put(key, value);
        }
        else if (action == 'g') {
            cin >> key;
            cout << lru.get(key) << endl;
        }
        else
            break;
    }
    return 0;
}
