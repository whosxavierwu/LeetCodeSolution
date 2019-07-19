// leetcode_92.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/reverse-linked-list-ii/
/*
Reverse a linked list from position m to n. Do it in one-pass.
Note: 1 ¡Ü m ¡Ü n ¡Ü length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/
#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		// v1: faster than 100.00%
		if (m == n)
			return head;
		ListNode* pTmpHead = NULL;
		ListNode* pTmpTail = NULL;
		ListNode* pBeforeM = NULL;
		ListNode* pTmp = NULL;
		int idx = 1;
		for (ListNode* p = head; p != NULL; ++idx) {
			if (idx == m-1)
				pBeforeM = p;
			if (idx < m) {
				p = p->next;
			}
			else if (idx == m) {
				pTmpTail = p;
				pTmpHead = p;
				p = p->next;
			}
			else if (idx < n) {
				pTmp = p->next;
				p->next = pTmpHead;
				pTmpHead = p;
				p = pTmp;
			}
			else if (idx == n) {
				pTmp = p->next;
				p->next = pTmpHead;
				pTmpHead = p;
				if (pBeforeM == NULL)  // in case m=1
					head = pTmpHead;
				else
					pBeforeM->next = pTmpHead;
				pTmpTail->next = pTmp;
				break;
			}
		}
		return head;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}

