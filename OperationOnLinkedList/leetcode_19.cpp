// leetcode_19.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		// v1: 4 ms, faster than 85.76% , 8.5 MB, less than 92.11% 
		// only one node
		if (head->next == NULL && n >= 1) return NULL;
		ListNode* faster = head;
		for (int i = 0; i < n; ++i)
			faster = faster->next;
		if (faster == NULL) return head->next;
		ListNode* slower = head;
		while (faster->next != NULL) {
			faster = faster->next;
			slower = slower->next;
		}
		slower->next = slower->next->next;
		return head;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
