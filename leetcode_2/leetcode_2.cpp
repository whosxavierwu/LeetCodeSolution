// leetcode_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/add-two-numbers/
/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
342 + 465 = 807.
*/
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// v1: faster than 74.41%
		ListNode* head = NULL;
		ListNode* tail = NULL;
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		int carry = 0;
		while (p1 != NULL || p2 != NULL) {
			int val = carry;
			if (p1 != NULL) {
				val += p1->val;
				p1 = p1->next;
			}
			if (p2 != NULL) {
				val += p2->val;
				p2 = p2->next;
			}
			carry = val / 10;
			val = val % 10;
			ListNode* tmp = new ListNode(val);
			if (head == NULL) {
				head = tmp;
				tail = tmp;
			}
			else {
				tail->next = tmp;
				tail = tail->next;
			}
		}
		if (carry > 0) {
			tail->next = new ListNode(carry);
			tail = tail->next;
		}
		return head;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
