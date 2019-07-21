// leetcode_933.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/number-of-recent-calls/

#include <iostream>
#include <queue>
#include <deque>
using namespace std;

// v1: faster than 69.81%
class RecentCounter {
	queue<int> q;
public:
	RecentCounter() {
		
	}

	int ping(int t) {
		while (!q.empty() && q.front() < (t - 3000))
			q.pop();
		q.push(t);
		return q.size();
	}
};

//// v2: faster than 60.18%
//class RecentCounter {
//	deque<int> q;
//public:
//	RecentCounter() {
//
//	}
//
//	int ping(int t) {
//		while (!q.empty() && q.front() < (t - 3000))
//			q.pop_front();
//		q.push_back(t);
//		return q.size();
//	}
//};


/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main()
{
    std::cout << "Hello World!\n";
}
