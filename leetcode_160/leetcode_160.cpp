// leetcode_160.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/intersection-of-two-linked-lists/
// Write a program to find the node at which the intersection of two singly linked lists begins.
//If the two linked lists have no intersection at all, return null.
//The linked lists must retain their original structure after the function returns.
//You may assume there are no cycles anywhere in the entire linked structure.
//Your code should preferably run in O(n) time and use only O(1) memory.


#include <iostream>
	

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		ListNode* pA = headA;
		ListNode* pB = headB;
		// calculate the length
		int lenA = 0;
		int lenB = 0;
		while (pA) {
			lenA++;
			pA = pA->next;
		}
		while (pB) {
			lenB++;
			pB = pB->next;
		}
		// let the longer one goes first
		pA = headA;
		pB = headB;
		if (lenA >= lenB){
			for (int i = 0; i < (lenA - lenB); i++)
				pA = pA->next;
		}
		else {
			for (int i = 0; i < (lenB - lenA); i++)
				pB = pB->next;
		}
		// now, pA & pB should be of same length
		// so, let them go together, and find out the intersection
		while ((pA != NULL) && (pB != NULL) && (pA != pB)) {
			pA = pA->next;
			pB = pB->next;
		}
		if ((pA == NULL) || (pB == NULL))
			return NULL;
		return pA;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

