// leetcode_876.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/middle-of-the-linked-list/
// Given a non-empty, singly linked list with head node head, return a middle node of linked list.
// If there are two middle nodes, return the second middle node.

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		if (head->next == NULL)
			return head;
		ListNode* p_step_1 = head;
		ListNode* p_step_2 = head;
		while (p_step_2->next != NULL) {
			p_step_1 = p_step_1->next;
			p_step_2 = p_step_2->next;
			if (p_step_2->next == NULL)
				break;
			p_step_2 = p_step_2->next;
		}
		return p_step_1;
	}
};

int main()
{
	int in_list[] = { 1, 2, 3, 4, 5, 6};
	ListNode* tmp_node = new ListNode(in_list[0]);
	ListNode* in_linked_list = tmp_node;
	ListNode* cur = in_linked_list;
	int len = size(in_list);
	for (int i = 1; i < len; i++) {
		tmp_node = new ListNode(in_list[i]);
		cur->next = tmp_node;
		cur = cur->next;
	}

	Solution s;
	ListNode* result = s.middleNode(in_linked_list);
	while (result) {
		cout << result->val << endl;
		result = result->next;
	}
	return 0;
}

