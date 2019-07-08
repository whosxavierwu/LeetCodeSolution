// leetcode_203.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/remove-linked-list-elements/

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
	ListNode* removeElements(ListNode* head, int val) {
		while ((head != NULL) && (head->val == val))
			head = head->next;
		if (head == NULL)
			return head;
		ListNode* tail = head;
		ListNode* cur = head->next;
		// find next survival
		while (tail) {
			while ((cur != NULL) && (cur->val == val))
				cur = cur->next;
			tail->next = cur;
			tail = tail->next;
			if (cur == NULL)
				break;
			cur = cur->next;
		}
		return head;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
