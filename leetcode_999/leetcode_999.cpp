// leetcode_999.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/available-captures-for-rook/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int numRookCaptures(vector<vector<char>>& board) {
		// v1: faster than 58.46% 
		int N = board.size();
		int x = -1, y = -1;
		bool found = false;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (board[i][j] == 'R') {
					x = i; 
					y = j;
					found = true;
					break;
				}
			}
			if (found) break;
		}
		int result = 0;
		for (int i = x - 1; i >= 0; --i) {
			if (board[i][y] == '.')
				continue;
			if (board[i][y] == 'p')
				result++;
			break;
		}
		for (int i = x + 1; i < N; ++i) {
			if (board[i][y] == '.')
				continue;
			if (board[i][y] == 'p')
				result++;
			break;
		}
		for (int j = y - 1; j >= 0; --j) {
			if (board[x][j] == '.')
				continue;
			if (board[x][j] == 'p')
				result++;
			break;
		}
		for (int j = y + 1; j < N; ++j) {
			if (board[x][j] == '.')
				continue;
			if (board[x][j] == 'p')
				result++;
			break;
		}
		return result;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}

