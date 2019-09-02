// leetcode_295.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/find-median-from-data-stream/
/*
Median is the middle value in an ordered integer list. If the size of the list is even, 
there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.


Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2


Follow up:

If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// v1: 152 ms, faster than 85.85% 
class MedianFinder {
	priority_queue<int, vector<int>, less<int>> lpq;
	priority_queue<int, vector<int>, greater<int>> rpq;
public:
	/** initialize your data structure here. */
	MedianFinder() {
		
	}

	void addNum(int num) {
		if (lpq.empty())
			lpq.push(num);
		else if (rpq.empty()) {
			if (num > lpq.top())
				rpq.push(num);
			else {
				rpq.push(lpq.top());
				lpq.pop();
				lpq.push(num);
			}
		}
		else if (num <= lpq.top())
			lpq.push(num);
		else
			rpq.push(num);

		while (lpq.size() > (1+rpq.size())) {
			rpq.push(lpq.top());
			lpq.pop();
		}
		while (rpq.size() > lpq.size()) {
			lpq.push(rpq.top());
			rpq.pop();
		}
	}

	double findMedian() {
		if (lpq.size() == rpq.size())
			return (lpq.top() + rpq.top()) / 2.0;
		else if (lpq.size() > rpq.size())
			return lpq.top();
		else
			return rpq.top();
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
	MedianFinder* obj = new MedianFinder();
	//obj->addNum(1);
	//cout << obj->findMedian() << endl;
	//obj->addNum(2);
	//cout << obj->findMedian() << endl;
	//obj->addNum(3);
	//cout << obj->findMedian() << endl;
	//obj->addNum(4);
	//cout << obj->findMedian() << endl;
	//obj->addNum(5);
	//cout << obj->findMedian() << endl;
	//obj->addNum(6);
	//cout << obj->findMedian() << endl;
	//obj->addNum(7);
	//cout << obj->findMedian() << endl;
	//obj->addNum(8);
	//cout << obj->findMedian() << endl;
	//obj->addNum(9);
	//cout << obj->findMedian() << endl;
	//obj->addNum(10);
	//cout << obj->findMedian() << endl;

	obj->addNum(-1);
	cout << obj->findMedian() << endl;
	obj->addNum(-2);
	cout << obj->findMedian() << endl;
	obj->addNum(-3);
	cout << obj->findMedian() << endl;
	obj->addNum(-4);
	cout << obj->findMedian() << endl;
	obj->addNum(-5);
	cout << obj->findMedian() << endl;
}

