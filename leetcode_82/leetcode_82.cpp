// leetcode_82.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

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
	ListNode* deleteDuplicates(ListNode* head) {
		// faster than 89.43% 
		bool toDelete = false;
		bool isStart = true;
		ListNode* tail = NULL;
		ListNode* cur = head;
		
		while (cur) {
			toDelete = false;
			while (cur !=NULL && cur->next != NULL && cur->val == cur->next->val) {
				cur = cur->next;
				toDelete = true;
			}
			if (toDelete) 
				cur = cur->next;
			else if (isStart) {
				tail = cur;
				head = tail;
				cur = cur->next;
				isStart = false;
			}else {
				tail->next = cur;
				cur = cur->next;
				tail = tail->next;
			}
		}
		if (toDelete) {
			if (tail == NULL)
				return NULL;
			else
				tail->next = NULL;
		}
		return head;
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
	vector<int> arr = { 1,2,3,3,4,4,5 };
	//vector<int> arr = { 1,1,1,2,3 };
	//vector<int> arr = { 1,2,2 };
	//vector<int> arr = { 1,1,2,2 };
	ListNode* head = arr2llist(arr);
	
	ListNode* result = sol.deleteDuplicates(head);
	ListNode* tmp = result;
	while (tmp) {
		cout << tmp->val << endl;
		tmp = tmp->next;
	}
	return 0;
}
