// leetcode_206.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/reverse-linked-list/
// A linked list can be reversed either iteratively or recursively. Could you implement both?

#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// how about recursive version?
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* new_head = NULL;
		ListNode* tmp = NULL;
		while (head) {
			if (new_head == NULL) {
				new_head = head;
				head = head->next;
				new_head->next = NULL;
			}
			else {
				tmp = head->next;
				head->next = new_head;
				new_head = head;
				head = tmp;
			}
		}
		return new_head;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

