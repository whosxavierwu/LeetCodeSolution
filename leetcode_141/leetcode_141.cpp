// leetcode_141.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/linked-list-cycle/
// Given a linked list, determine if it has a cycle in it.
// Can you solve it using O(1) (i.e. constant) memory?



#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode* head) {
		// v1: faster than 80.38% 
		ListNode* step1 = head;
		ListNode* step2 = head;
		while ((step1 != NULL) && (step2 != NULL)) {
			step1 = step1->next;
			step2 = step2->next;
			if (step1 == NULL || step2 == NULL) break;
			step2 = step2->next;
			if (step1 == step2)
				return true;
		}
		return false;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
