// leetcode_92.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/reverse-linked-list-ii/
/*
Reverse a linked list from position m to n. Do it in one-pass.
Note: 1 ¡Ü m ¡Ü n ¡Ü length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/
#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {

	}
};
int main()
{
    std::cout << "Hello World!\n";
}

