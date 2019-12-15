// leetcode_5283.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://leetcode.com/contest/weekly-contest-167/problems/convert-binary-number-in-a-linked-list-to-integer/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
  
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* cur = head;
        int result = 0;
        while (cur != NULL) {
            result = (result << 1) + cur->val;
            cur = cur->next;
        }
        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
