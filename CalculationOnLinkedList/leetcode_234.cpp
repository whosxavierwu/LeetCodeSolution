// leetcode_234.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/palindrome-linked-list/
// Given a singly linked list, determine if it is a palindrome
// Could you do it in O(n) time and O(1) space?

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
	bool isPalindrome(ListNode* head) {
		// v1: faster than 98.33%
		if (head == NULL || head->next == NULL)
			return true;
		if (head->next != NULL && head->next->next == NULL)
			return head->val == head->next->val;

		// step1 & step2, find out the med point
		ListNode* step1 = head;
		ListNode* step2 = head;
		ListNode* head1 = NULL;
		ListNode* head2 = NULL;
		while (step2) {
			step2 = step2->next;
			step2 = step2->next;
			// always take the point before med
			if (step2!=NULL && step2->next!=NULL)
				step1 = step1->next;
			else {
				head1 = step1;
				if (step2 == NULL)
					head2 = head1->next;
				else
					head2 = head1->next->next;
				break;
			}
		}

		// reverse the first half
		ListNode* newHead = NULL;
		ListNode* cur = head;
		while (newHead != head1) {
			ListNode* tmp = cur->next;
			cur->next = newHead;
			newHead = cur;
			cur = tmp;
		}

		// compare two list
		while (newHead != NULL && head2 != NULL) {
			if (newHead->val != head2->val)
				return false;
			newHead = newHead->next;
			head2 = head2->next;
		}
		return true;
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
	vector<int> vec = { 1, 0, 1 };
	ListNode* head = arr2llist(vec);
	cout << sol.isPalindrome(head) << endl;
	return 0;
}

