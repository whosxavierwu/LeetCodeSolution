// leetcode_707.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/design-linked-list/
// All values will be in the range of [1, 1000].
// The number of operations will be in the range of[1, 1000].
// Please do not use the built - in LinkedList library.

#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class MyLinkedList {
	ListNode* head;
	ListNode* tail;
	int len;
public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		head = NULL;
		tail = NULL;
		len = 0;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index >= len)
			return -1;
		ListNode* cur = head;
		for (int i = 0; i < index; ++i)
			cur = cur->next;
		return cur->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		ListNode tmp(val);
		if (head == NULL) {
			head = &tmp;
			tail = head;
		}
		else {
			tmp.next = head;
			head = &tmp;
		}
		++len;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		ListNode tmp(val);
		if (head == NULL) {
			head = &tmp;
			tail = head;
		}
		else {
			tail->next = &tmp;
			tail = tail->next;
		}
		++len;
	}

	/** Add a node of value val before the index-th node in the linked list. 
	If index equals to the length of linked list, the node will be appended to the end of linked list. 
	If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index == len)
			addAtTail(val);
		else if (index == 0)
			addAtHead(val);
		else if (index < len){
			ListNode* prev = head;
			ListNode* cur = head;
			for (int i = 0; i < index; ++i) {
				prev = cur;
				cur = cur->next;
			}
			prev->next = new ListNode(val);
			prev = prev->next;
			prev->next = cur;
			++len;
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index >= len)
			return;
		if (index == 0)
			head = head->next;
		else {
			ListNode* prev = head;
			ListNode* cur = head;
			for (int i = 0; i < index; ++i) {
				prev = cur;
				cur = cur->next;
			}
			prev->next = cur->next;
		}
		--len;
	}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
    std::cout << "Hello World!\n";
}
