// leetcode_950.cpp : This file contains the 'main' function. Program execution begins and ends there.
// todo https://leetcode.com/problems/reveal-cards-in-increasing-order/
/*
In a deck of cards, every card has a unique integer.  You can order the deck in any order you want.

Initially, all the cards start face down (unrevealed) in one deck.

Now, you do the following steps repeatedly, until all cards are revealed:

Take the top card of the deck, reveal it, and take it out of the deck.
If there are still cards in the deck, put the next top card of the deck at the bottom of the deck.
If there are still unrevealed cards, go back to step 1.  Otherwise, stop.
Return an ordering of the deck that would reveal the cards in increasing order.

The first entry in the answer is considered to be the top of the deck.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
using namespace std;

// v1:  98.56%
//class Solution {
//public:
//	vector<int> deckRevealedIncreasing(vector<int>& deck) {
//		int len = deck.size();
//		sort(deck.begin(), deck.end());
//		vector<int> result(len);
//		result[0] = deck[0];
//		for (int i = 1, p = 0; i < len; ++i) {
//			// find the second empty slot
//			for (int j = 0; j < 2; ) {
//				p = (p + 1) % len;
//				if (result[p] == 0) ++j;
//			}
//			result[p] = deck[i];
//		}
//		return result;
//	}
//};

// v2: 16 ms, faster than 30.82% 
//class Solution {
//public:
//	vector<int> deckRevealedIncreasing(vector<int>& deck) {
//		int len = deck.size();
//		vector<int> result(len);
//		sort(deck.begin(), deck.end());
//		result[len - 1] = deck.back();
//		for (int i = len - 2; i >= 0; --i) {
//			result[i] = deck[i];
//			rotate(result.begin() + i + 1, result.begin() + len - 1, result.end());
//		}
//		return result;
//	}
//};

// v3 8 ms, faster than 98.56%
class Solution {
public: 
	vector<int> deckRevealedIncreasing(vector<int>& deck) {
		deque<int> dq;
		sort(deck.begin(), deck.end(), greater<int>());
		for (int i = 0; i < deck.size(); ++i) {
			dq.push_front(deck[i]);
			dq.insert(dq.begin() + 1, dq.back());
			dq.pop_back();
		}
		return vector<int>(dq.begin(), dq.end());
	}
};

int main()
{
	Solution sol;
	vector<int> v = { 17,13,11,2,3,5,7 };
	vector<int> result = sol.deckRevealedIncreasing(v);
	for (int& n : result)
		cout << n << " " << endl;
}

