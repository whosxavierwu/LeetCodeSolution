// leetcode_5073.cpp : This file contains the 'main' function. Program execution begins and ends there.
// todo https://leetcode.com/contest/biweekly-contest-9/problems/minimum-knight-moves/
 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minKnightMoves(int x, int y) {
		return (int)knightDistance(x, y);
	}
	long knightDistance(long r, long c)
	{
		r = abs(r); c = abs(c);
		if (r + c == 0) return 0;
		if (r + c == 1) return 3;
		if (r == 2 && c == 2)return 4;

		// why??? 
		long step = max({ (r + 1) / 2, (c + 1) / 2, (r + c + 2) / 3 });
		step += (step ^ r ^ c) & 1;
		return step;
	}
};

//class Solution {
//public:
//	int minKnightMoves(int x, int y) {
//		// TLE
//		//queue<vector<int>> q;
//		//q.push({ 0, 0, 0 });
//		//while (!q.empty()) {
//		//	vector<int> front = q.front();
//		//	q.pop();
//		//	if (front[0] == x && front[1] == y) return front[2];
//		//	if ((front[0] >= 0) ^ (x >= 0)) continue;
//		//	if ((front[1] >= 0) ^ (y >= 0)) continue;
//		//	q.push({ front[0] + 2, front[1] + 1, front[2] + 1 });
//		//	q.push({ front[0] + 2, front[1] - 1, front[2] + 1 });
//		//	q.push({ front[0] - 2, front[1] + 1, front[2] + 1 });
//		//	q.push({ front[0] - 2, front[1] - 1, front[2] + 1 });
//		//	q.push({ front[0] + 1, front[1] + 2, front[2] + 1 });
//		//	q.push({ front[0] + 1, front[1] - 2, front[2] + 1 });
//		//	q.push({ front[0] - 1, front[1] + 2, front[2] + 1 });
//		//	q.push({ front[0] - 1, front[1] - 2, front[2] + 1 });
//		//}
//		//return 0;
//
//		if (x == 0 && y == 0) return 0; 
//		x = abs(x); y = abs(y);
//		return min(minKnightMoves(x - 2, y - 1), minKnightMoves(x - 1, y - 2)) + 1;
//	}
//};

int main()
{
	Solution sol;
	cout << sol.minKnightMoves(2, 112) << endl;
}
