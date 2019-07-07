// leetcode_21.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/merge-two-sorted-lists/
// Merge two sorted linked lists and return it as a new list. 
// The new list should be made by splicing together the nodes of the first two lists.

#include <iostream>
#include<vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		ListNode* p_cur = NULL;
		ListNode* head = NULL;
		ListNode* p_tmp = NULL;
		while ((p1 != NULL) || (p2 != NULL)) {
			if (p1 == NULL) {
				p_tmp = p2;
				p2 = p2->next;
			}
			else if (p2 == NULL) {
				p_tmp = p1;
				p1 = p1->next;
			}
			else if (p1->val <= p2->val) {
				p_tmp = p1;
				p1 = p1->next;
			}
			else {
				p_tmp = p2;
				p2 = p2->next;
			}
			if (head == NULL) {
				head = p_tmp;
				p_cur = p_tmp;
			}
			else {
				p_cur->next = p_tmp;
				p_cur = p_cur->next;
			}
		}
		return head;
	}
};

ListNode* arr2llist(vector<int> &arr) {
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
	vector<int> arr_1 = {1, 2, 4};
	ListNode* llist_1 = arr2llist(arr_1);
	vector<int> arr_2 = { 1, 3, 4 };
	ListNode* llist_2 = arr2llist(arr_2);

	Solution s;
	ListNode* result = s.mergeTwoLists(llist_1, llist_2);
	while (result) {
		cout << result->val << endl;
		result = result->next;
	}
	return 0;
}