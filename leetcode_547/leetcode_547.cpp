// leetcode_547.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/friend-circles/

#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

class Solution {
public:
	int findGangMaster(int x, vector<int>& bossOf) {
		return bossOf[x] == x ? x : findGangMaster(bossOf[x], bossOf);
	}
	int findCircleNum(vector<vector<int>>& M) {
		// v1: faster than 51.10%, too slow!!!
		//int len = M.size();
		//vector<int> group(len, -1);
		//set<int> users;  // users unchecked 
		//stack<int> sta;
		//int gid = 0;
		//for (int i = 0; i < len; ++i)
		//	users.insert(i);
		//while (!users.empty()) {
		//	int u = *users.begin();
		//	group[u] = gid;
		//	gid++;
		//	users.erase(u);
		//	sta.push(u);
		//	while (!sta.empty()) {
		//		int v = sta.top();
		//		sta.pop();
		//		for (int i = 0; i < len; ++i) {
		//			if (M[v][i] > 0 && group[i] < 0) {
		//				group[i] = group[v];
		//				sta.push(i);
		//				users.erase(i);
		//			}
		//		}
		//	}
		//}
		//return gid;

		//// v2:  faster than 51.10% 
		//// f[i] = f[i-1] if all friends of i in same group 
		//// f[i] = 1+f[i-1] if i has no friends
		//// f[i] = f[i-1]+(k-1) if friends of i are in k groups
		//// f[0] = 1; f[len-1] is the result
		//int len = M.size();
		//vector<int> count(len, -1);
		//vector<int> group(len, -1);
		//// setting for user 0
		//group[0] = 0;
		//int gid = 1;
		//count[0] = 1;
		//for (int i = 1; i < len; ++i) {
		//	set<int> gids;
		//	for (int j = 0; j < i; ++j){
		//		if (M[i][j] > 0) {
		//			// friends of i
		//			gids.insert(group[j]);
		//		}
		//	}
		//	if (gids.empty()) {
		//		// no friends
		//		group[i] = gid;
		//		++gid;
		//		count[i] = count[i - 1] + 1;
		//	}
		//	else if (gids.size() == 1) {
		//		// all friends are in the same group 
		//		group[i] = *gids.begin();
		//		count[i] = count[i - 1];
		//	}
		//	else {
		//		// groups in gids should be merge to one group
		//		// because of user i
		//		group[i] = gid;
		//		++gid;
		//		count[i] = count[i - 1] - gids.size() + 1;
		//		for (int j = 0; j < i; ++j) {
		//			if (gids.find(group[j]) != gids.end()) {
		//				group[j] = group[i];
		//			}
		//		}
		//	}
		//}
		//return count[len - 1];

		// v3: faster than 97.31% 
		if (M.empty()) return 0;
		int len = M.size();
		vector<int> bossOf(len, 0);  // save the boss of user i
		// initially, i is the boss of himself
		for (int i = 0; i < len; i++)    
			bossOf[i] = i;
		// initially, every gang consists of one people
		int numOfGangs = len;  
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {   
				if (M[i][j] > 0) {
					int master1 = findGangMaster(i, bossOf);
					int master2 = findGangMaster(j, bossOf);
					if (master1 != master2) {
						// now merge two gangs, because of the friendship of i & j
						bossOf[master2] = master1;
						numOfGangs--;
					}
				}
			}
		}
		return numOfGangs;
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> mat = { {1,1,0},{1,1,0},{0,0,1} };
	int result = sol.findCircleNum(mat);
	cout << result << endl;
	return 0;
}

