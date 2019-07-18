// leetcode_445.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/add-two-numbers-ii/
/*
You are given two non-empty linked lists representing two non-negative integers. 
The most significant digit comes first and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// v1: faster than 58.12%, not fast enough!!!
		// find out the length difference
		ListNode* p = NULL;
		int len1 = 0, len2 = 0;
		for (p = l1; p != NULL; ++len1, p = p->next)
			;
		for (p = l2; p != NULL; ++len2, p = p->next)
			;
		if (len1 == 0)
			return l2;
		else if (len2 == 0)
			return l1;
		int lenDiff = abs(len1 - len2);
		ListNode* pLong = (len1 > len2) ? l1 : l2;
		ListNode* pShort = (len1 <= len2) ? l1 : l2;
		// directly add up put the sums to stack
		stack<int> sta;
		for (int i = 0; i < lenDiff; ++i, pLong = pLong->next) {
			sta.push(pLong->val);
		}
		for (; pLong != NULL && pShort != NULL; pLong=pLong->next, pShort=pShort->next) {
			sta.push(pLong->val + pShort->val);
		}
		// get sums from stack and construct a list
		ListNode* head = NULL;
		int carry = 0;
		while (!sta.empty()) {
			int val = sta.top() + carry;
			carry = val / 10;
			val = val % 10;
			if (head == NULL) {
				head = new ListNode(val);
			}
			else {
				p = new ListNode(val);
				p->next = head;
				head = p;
			}
			sta.pop();
		}
		if (carry > 0) {
			p = new ListNode(carry);
			p->next = head;
			head = p;
		}
		return head;

		// v2: faster than 80.20% 
		stack<int> s1, s2; // store digits in stack
		for (; l1; l1 = l1->next) s1.push(l1->val);
		for (; l2; l2 = l2->next) s2.push(l2->val);

		ListNode* res = new ListNode(0), * tmp = NULL;
		for (int sum = 0; !s1.empty() || !s2.empty(); tmp = new ListNode(sum /= 10), tmp->next = res, res = tmp) {
			if (!s1.empty()) sum += s1.top(), s1.pop(); // get digit sum
			if (!s2.empty()) sum += s2.top(), s2.pop();
			res->val = sum % 10;
		}
		return res->val ? res : res->next;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
