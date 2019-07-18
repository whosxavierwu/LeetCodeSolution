// leetcode_1019.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/next-greater-node-in-linked-list/
/*
We are given a linked list with head as the first node.  
Let's number the nodes in the list: node_1, node_2, node_3, ... etc.
Each node may have a next larger value: for node_i, next_larger(node_i) is 
the node_j.val such that j > i, node_j.val > node_i.val, and j is the smallest possible choice.  

If such a j does not exist, the next larger value is 0.
Return an array of integers answer, where answer[i] = next_larger(node_{i+1}).

Input: [2,1,5]
Output: [5,5,0]

Input: [2,7,4,3,5]
Output: [7,0,5,5,0]

Input: [1,7,5,1,9,2,5,1]
Output: [7,9,9,9,0,5,0,0]

Note:

1 <= node.val <= 10^9 for each node in the linked list.
The given list has length in the range [0, 10000].
*/

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
	vector<int> nextLargerNodes(ListNode* head) {
		// v1: faster than 16.15% , too slow!!!
		//vector<int> result;
		//for (ListNode* p = head; p != NULL; p = p->next) {
		//	if (p->next == NULL) {
		//		result.push_back(0);
		//		break;
		//	}
		//	bool found = false;
		//	for (ListNode* q = p->next; q != NULL; q = q->next) {
		//		if (q->val > p->val) {
		//			result.push_back(q->val);
		//			found = true;
		//			break;
		//		}
		//	}
		//	if (!found)
		//		result.push_back(0);
		//}
		//return result;

		// v2: WA
		vector<int> result;
		ListNode* p = head;
		while (p != NULL) {
			if (p->next == NULL) {
				result.push_back(0);
				break;
			}
			int cnt = 1;
			ListNode* q = p->next;
			while (q != NULL) {
				if (q->val < p->val) {
					++cnt;
				}
				else if (q->val == p->val) {
					// todo error here
					++cnt;
				}
				else {
					for (int i = 0; i < cnt; ++i)
						result.push_back(q->val);
					p = q;
					break;
				}
				q = q->next;
			}
			if (q == NULL) {
				result.push_back(0);
				p = p->next;
			}
		}
		
		return result;
	}
};

ListNode* arr2llist(vector<int>& arr) {
	int len = size(arr);
	ListNode* tmp_node = new ListNode(arr[0]);
	ListNode* llist = tmp_node;
	ListNode* cur = llist;
	for (int i = 1; i < len; i++) {
		tmp_node = new ListNode(arr[i]);
		cur->next = tmp_node;
		cur = cur->next;
	}
	return llist;
}

int main()
{
	Solution sol;
	//vector<int> arr = { 2,7,4,3,5 };
	vector<int> arr = { 9,7,6,7,6,9 };
	ListNode* head = arr2llist(arr);
	vector<int> result = sol.nextLargerNodes(head);
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << endl;
}

