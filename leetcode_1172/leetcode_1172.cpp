// leetcode_1172.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/dinner-plate-stacks/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

// v1: 520 ms, faster than 11.11%, 154 MB, less than 100.00%
class DinnerPlates {
	int _capacity;
	vector<vector<int>> data;
	int firstNonFullStack;
	int lastNonEmptyStack;
public:
	DinnerPlates(int capacity) {
		_capacity = capacity;
		firstNonFullStack = 0;
		lastNonEmptyStack = -1;
	}

	void push(int val) {
		while (firstNonFullStack < data.size() && data[firstNonFullStack].size() >= _capacity) {
			++firstNonFullStack;
		}
		if (firstNonFullStack >= data.size()) {
			data.push_back({ val });
			lastNonEmptyStack = firstNonFullStack;
		}
		else {
			data[firstNonFullStack].push_back(val);
		}
	}

	int pop() {
		while (lastNonEmptyStack >= 0 && data[lastNonEmptyStack].empty()) {
			--lastNonEmptyStack;
		}
		if (lastNonEmptyStack < 0) return -1;
		int tmp = data[lastNonEmptyStack].back();
		data[lastNonEmptyStack].pop_back();
		return tmp;
	}

	int popAtStack(int index) {
		if (index >= data.size()) return -1;
		if (data[index].empty()) return -1;
		int tmp = data[index].back();
		data[index].pop_back();
		if (index < firstNonFullStack)
			firstNonFullStack = index;
		return tmp;
	}
};

// v2 592 ms, faster than 11.11% , 154 MB, less than 100.00%
//class DinnerPlates {
//	int _capacity;
//	vector<vector<int>> data;
//	priority_queue<int, vector<int>, greater<int>> nonFullStacks;
//	priority_queue<int, vector<int>, less<int>> nonEmptyStacks;
//public:
//	DinnerPlates(int capacity) {
//		_capacity = capacity;
//	}
//
//	void push(int val) {
//		if (nonFullStacks.empty()) {
//			data.push_back({ val });
//			nonFullStacks.push(data.size() - 1);
//			nonEmptyStacks.push(data.size() - 1);
//		}
//		else {
//			int fistNonFullStack = nonFullStacks.top();
//			data[fistNonFullStack].push_back(val);
//			if (data[fistNonFullStack].size() >= _capacity) {
//				nonFullStacks.pop();
//			}
//		}
//	}
//
//	int pop() {
//		if (nonEmptyStacks.empty()) return -1;
//		while (data[nonEmptyStacks.top()].empty()) {
//			nonEmptyStacks.pop();
//		}
//		int lastNonEmptySatck = nonEmptyStacks.top();
//		int tmp = data[lastNonEmptySatck].back();
//		data[lastNonEmptySatck].pop_back();
//		if (data[lastNonEmptySatck].empty())
//			nonEmptyStacks.pop();
//		return tmp;
//	}
//
//	int popAtStack(int index) {
//		if (index >= data.size()) return -1;
//		if (data[index].empty()) return -1;
//		int tmp = data[index].back();
//		data[index].pop_back();
//		if (nonFullStacks .empty() || index < nonFullStacks.top())
//			nonFullStacks.push(index);
//		return tmp;
//	}
//};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
int main()
{
	DinnerPlates* obj = new DinnerPlates(2);
	obj->push(1);
	obj->push(2);
	obj->push(3);
	obj->push(4);
	obj->push(5);
	cout << obj->popAtStack(0) << endl;
	obj->push(20);
	obj->push(21);
	cout << obj->popAtStack(0) << endl;
	cout << obj->popAtStack(2) << endl;
	cout << obj->pop() << endl;
	cout << obj->pop() << endl;
	cout << obj->pop() << endl;
	cout << obj->pop() << endl;
	cout << obj->pop() << endl;
}
