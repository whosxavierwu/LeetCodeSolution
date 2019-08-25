// leetcode_1171.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeZeroSumSublists(ListNode* head) {
		if (head == NULL) return NULL;
		if (head->next == NULL) return head->val == 0 ? NULL : head;
		ListNode* cur = head;
		int sum = 0;
		while (cur != NULL) {
			sum += cur->val;
			if (sum == 0) {
				head = cur->next;
				return removeZeroSumSublists(head);
			}
			cur = cur->next;
		}
		head->next = removeZeroSumSublists(head->next);
		return head;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
