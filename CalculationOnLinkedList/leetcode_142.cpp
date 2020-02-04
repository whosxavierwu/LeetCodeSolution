// leetcode_142.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/linked-list-cycle-ii/
/*
Given a linked list, return the node where the cycle begins. 
If there is no cycle, return null.

To represent a cycle in the given linked list, 
we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. 
If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.

Follow-up:
Can you solve it without using extra space?

*/

#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		// v1: faster than 97.61%, less than 97.62%
		ListNode* p1 = head;
		ListNode* p2 = head;
		while (p1 && p2) {
			p1 = p1->next;
			p2 = p2->next;
			if (!p1 || !p2) return NULL;
			p2 = p2->next;
			if (p1 == p2) break;
		}
		if (!p1 || !p2) return NULL;
		p1 = head;
		while (p1 != p2) {
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	}
};
//
//int main()
//{
//    std::cout << "Hello World!\n";
//}
