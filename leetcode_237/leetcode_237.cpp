// leetcode_237.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/delete-node-in-a-linked-list/
// Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
//The linked list will have at least two elements.
//All of the nodes' values will be unique.
//The given node will not be the tailand it will always be a valid node of the linked list.
//Do not return anything from your function.
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		node->next = node->next->next;
	}
};

int main()
{
    std::cout << "Hello World! from 237\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
