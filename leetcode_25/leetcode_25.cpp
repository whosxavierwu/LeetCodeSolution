// leetcode_25.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/reverse-nodes-in-k-group/
/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseSingleGroup(ListNode* oldHead, ListNode* oldTail) {
		// IN: oldHead -> a1->...ak -> oldTail
		// OUT: oldTail->ak->...a1 ->oldHead
		ListNode* newHead = oldTail->next;
		ListNode* newTail = oldTail->next;
		ListNode* cur = oldHead;
		while (cur != newTail) {
			ListNode *next = cur->next;
			cur->next = newHead;
			newHead = cur;
			cur = next;
		}
		return newHead;
	}
	ListNode* reverseKGroup(ListNode* head, int k) {
		// v1: faster than 97.84% 
		if (k <= 1)
			return head;
		ListNode* newHead = NULL;
		ListNode* newTail = NULL;
		ListNode* tmpHead = head;
		ListNode* tmpTail = head;
		bool isEnd = false;
		while (!isEnd) {
			for (int i = 0; i < k-1; ++i) {
				if (tmpTail == NULL) {
					isEnd = true;
					break;
				}
				tmpTail = tmpTail->next;
			}
			if (isEnd || tmpTail == NULL) {
				break;
			}
			if (newHead == NULL) {
				newHead = reverseSingleGroup(tmpHead, tmpTail);
			}
			else {
				newTail->next = reverseSingleGroup(tmpHead, tmpTail);
			}
			newTail = tmpHead;
			tmpHead = newTail->next;
			tmpTail = tmpHead;
		}
		if (newHead == NULL)
			newHead = head;
		return newHead;
	}
};

ListNode* arr2llist(vector<int>& arr) {
	int len = size(arr);
	ListNode* tmp_node = new ListNode(arr[0]);
	ListNode* llist = tmp_node;
	ListNode* cur = llist;
	for (int i = 1; i < len; i++) {
		tmp_node = new ListNode(arr[i]);
		cur->next = tmp_node;
		cur = cur->next;
	}
	return llist;
}

int main()
{
	Solution sol; 
	vector<int> arr = { 1, 2, 3, 4, 5 };
	int k = 2;
	ListNode* head = arr2llist(arr);
	ListNode* result = sol.reverseKGroup(head, k);
	return 0;
}
