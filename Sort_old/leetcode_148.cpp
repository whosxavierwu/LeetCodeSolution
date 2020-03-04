// leetcode_148.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/sort-list/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next; 
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	// v1: 772 ms, faster than 5.17%
	//ListNode* sortList(ListNode* head) {
	//	if (!head) return NULL;
	//	ListNode* newHead = head;
	//	ListNode* cur = head->next;
	//	newHead->next = NULL;
	//	while (cur) {
	//		ListNode* next = cur->next;
	//		if (cur->val <= newHead->val) {
	//			cur->next = newHead;
	//			newHead = cur;
	//		}
	//		else {
	//			ListNode* p = newHead;
	//			while (p->next != NULL && cur->val > p->next->val) {
	//				p = p->next;
	//			}
	//			cur->next = p->next;
	//			p->next = cur;
	//		}
	//		cur = next;
	//	}
	//	return newHead;
	//}

	// v2: 48 ms, faster than 57.31% 
	ListNode* sortList(ListNode* head) {
		if (!head) return NULL;
		vector<ListNode*> vec;
		ListNode* cur = head;
		while (cur) {
			vec.push_back(cur);
			cur = cur->next;
		}
		sort(vec.begin(), vec.end(), [](ListNode* x, ListNode* y) {return x->val < y->val; });
		int len = vec.size();
		ListNode* newHead = vec[0];
		for (int i = 0; i < len - 1; ++i) {
			vec[i]->next = vec[i + 1];
		}
		vec[len - 1]->next = NULL;
		return vec[0];
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
