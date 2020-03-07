// leetcode_23.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/merge-k-sorted-lists/
// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		ListNode* p_cur = NULL;
		ListNode* head = NULL;
		ListNode* p_tmp = NULL;
		while ((p1 != NULL) || (p2 != NULL)) {
			if (p1 == NULL) {
				p_tmp = p2;
				p2 = p2->next;
			}
			else if (p2 == NULL) {
				p_tmp = p1;
				p1 = p1->next;
			}
			else if (p1->val <= p2->val) {
				p_tmp = p1;
				p1 = p1->next;
			}
			else {
				p_tmp = p2;
				p2 = p2->next;
			}
			if (head == NULL) {
				head = p_tmp;
				p_cur = p_tmp;
			}
			else {
				p_cur->next = p_tmp;
				p_cur = p_cur->next;
			}
		}
		return head;
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int numOfList = lists.size();
		if (numOfList == 0)
			return NULL;
		if (numOfList == 1)
			return lists[0];
		if (numOfList == 2)
			return mergeTwoLists(lists[0], lists[1]);
		// v4: every two list, we use mergeTwoLists
		// it's much faster!!! faster than 94%! why?
		vector<ListNode*> tmp;
		for (int i = 0; i < numOfList; i += 2) {
			if ((i + 1) >= numOfList) {
				tmp.push_back(lists[i]);
			}
			else {
				tmp.push_back(mergeTwoLists(lists[i], lists[i + 1]));
			}
		}
		return mergeKLists(tmp);

		// v1: use mergeTwoLists, really slow... faster than only 13.89% submission
		//ListNode* result = lists[0];
		//for (int i = 1; i < numOfList; ++i) {
		//	result = mergeTwoLists(result, lists[i]);
		//}
		//return result;

		// v2: always find the smallest one. Much slower than v1......
		//ListNode* head = NULL;
		//ListNode* tail = NULL;
		//vector<ListNode*> cur(numOfList);
		//int numOfVisitedList = 0;
		//vector<int> isVisitedList(numOfList, 0);
		//for (int i = 0; i < numOfList; i++) {
		//	cur[i] = lists[i];
		//	if (cur[i] == NULL) {
		//		isVisitedList[i] = 1;
		//		numOfVisitedList++;
		//	}
		//}
		//while (numOfVisitedList < numOfList) {
		//	ListNode* pMin = NULL;
		//	int iMin = -1; 
		//	// find the minimum
		//	for (int i = 0; i < numOfList; i++) {
		//		if (isVisitedList[i])
		//			continue;
		//		if ((pMin == NULL) || (cur[i]->val < pMin->val)) {
		//			pMin = cur[i];
		//			iMin = i;
		//		}
		//	}
		//	// add the min node to result list
		//	if (head == NULL) {
		//		head = cur[iMin];
		//		tail = cur[iMin];
		//	}
		//	else {
		//		tail->next = cur[iMin];
		//		tail = tail->next;
		//	}
		//	// let the min node goes
		//	cur[iMin] = cur[iMin]->next;
		//	if (cur[iMin] == NULL) {
		//		isVisitedList[iMin] = 1;
		//		numOfVisitedList++;
		//	}
		//}
		//return head;
		
		// v3: combine lists directly, then use bubble sort / insertion sort

		
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

