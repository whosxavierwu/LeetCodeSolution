// leetcode_138.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/copy-list-with-random-pointer/
/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.


Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
Example 4:

Input: head = []
Output: []
Explanation: Given linked list is empty (null pointer), so return null.


Constraints:

-10000 <= Node.val <= 10000
Node.random is null or pointing to a node in the linked list.
Number of Nodes will not exceed 1000.

*/
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // v2  8 ms, faster than 92.22%
        Node* newHead;
        Node* p1;
        Node* p2;
        if (head == NULL) return NULL;
        for (p1 = head; p1 != NULL; p1 = p1->next) {
            p2 = new Node(p1->val);
            p2->next = p1->random;
            p1->random = p2;
        }
        newHead = head->random;
        for (p1 = head; p1 != NULL; p1 = p1->next) {
            p2 = p1->random;
            p2->random = p2->next ? p2->next->random : NULL;
        }
        for (p1 = head; p1 != NULL; p1 = p1->next) {
            p2 = p1->random;
            p1->random = p2->next;
            p2->next = p1->next ? p1->next->random : NULL;
        }
        return newHead;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
