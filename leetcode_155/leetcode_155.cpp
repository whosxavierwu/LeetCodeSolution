// leetcode_155.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/min-stack/
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// v1: faster than 18.78%
//class MinStack {
//	vector<int> vec;
//	int min;
//public:
//	/** initialize your data structure here. */	
//	MinStack() {
//		min = INT_MAX;
//	}
//
//	void push(int x) {
//		if (x < min) 
//			min = x;
//		vec.push_back(x);
//	}
//
//	void pop() {
//		int tmp = top();
//		vec.pop_back();
//		if (tmp <= min) {
//			min = INT_MAX;
//			for (int i = 0; i < vec.size(); ++i)
//				if (vec[i] < min)
//					min = vec[i];
//		}
//	}
//
//	int top() {
//		return vec[vec.size() - 1];
//	}
//
//	int getMin() {
//		return min;
//	}
//};

//// v2: faster than 98.40%
//struct MyStackNode {
//	int val;
//	int min;
//	MyStackNode(int v, int m): val(v), min(m) {}
//};
//class MinStack {
//	stack<MyStackNode> sta;
//public:
//	/** initialize your data structure here. */
//	MinStack() {
//	}
//
//	void push(int x) {
//		int min = INT_MAX;
//		if (!sta.empty())
//			min = fmin(sta.top().min, sta.top().val);
//		MyStackNode tmp(x, min);
//		sta.push(tmp);
//	}
//
//	void pop() {
//		sta.pop();
//	}
//
//	int top() {
//		return sta.top().val;
//	}
//
//	int getMin() {
//		return fmin(sta.top().val, sta.top().min);
//	}
//};

class MinStack {
    vector<pair<int, int>> sta;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        int prev_min = sta.empty() ? x : sta.back().second;
        sta.push_back({ x, min(prev_min, x) });
    }

    void pop() {
        sta.pop_back();
    }

    int top() {
        return sta.back().first;
    }

    int getMin() {
        return sta.back().second;
    }
};


int main()
{
    std::cout << "Hello World!\n";
}
