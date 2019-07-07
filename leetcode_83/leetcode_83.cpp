// leetcode_83.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Given a sorted linked list, delete all duplicates such that each element appear only once.
//Input: 1->1->2
//Output : 1->2
//Input : 1->1->2->3->3
//Output : 1->2->3


#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL)
			return head;

		//ListNode *result = NULL;
		//int prev = head->val - 1;
		//ListNode *latest = NULL;
		//ListNode* tmp_node = NULL;
		//while (head) {
		//	if (head->val != prev) {
		//		prev = head->val;
		//		tmp_node = new ListNode(head->val);
		//		if (result == NULL) {
		//			result = tmp_node;
		//			latest = tmp_node;
		//		} else {
		//			latest->next = tmp_node;
		//			latest = latest->next;
		//		}
		//	}
		//	head = head->next;
		//}
		//return result;

		ListNode* latest = head;
		ListNode* cur = head;
		while (cur) {
			if (cur->val != latest->val) {
				latest->next = cur;
				latest = latest->next;
			}
			cur = cur->next;
		}
		latest->next = NULL;
		return head;
	}
};

int main()
{
	int in_list[] = {1, 1, 2, 3, 3};
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
	ListNode*result = s.deleteDuplicates(in_linked_list);
	while (result) {
		cout << result->val << endl;
		result = result->next;
	}
	return 0;
}
