// leetcode_1203.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-155/problems/sort-items-by-groups-respecting-dependencies/
// https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;


class Solution {
public:
	vector<int> sortItems(int numOfItem, int numOfGroup, vector<int>& group, vector<vector<int>>& beforeItems) {
		vector<set<int>> group2item(numOfGroup);

		for (int item = 0; item < group.size(); item++) {
			if (group[item] == -1) {
				group[item] = numOfGroup++;
				group2item.push_back({});
			}
			group2item[group[item]].insert(item);
		}

		vector<int> groupInNum(numOfGroup);
		vector<set<int>> groupDir(numOfGroup);

		vector<int> itemInNum(numOfItem);
		vector<set<int>> itemDir(numOfItem);

		for (int toItem = 0; toItem < numOfItem; toItem++) {
			int toGroup = group[toItem];
			for (auto fromItem : beforeItems[toItem]) {
				int fromGroup = group[fromItem];

				if (toGroup == fromGroup) {
					itemDir[fromItem].insert(toItem);
					itemInNum[toItem]++;
				}
				else {
					if (groupDir[fromGroup].count(toGroup) == 0) {
						groupDir[fromGroup].insert(toGroup);
						groupInNum[toGroup]++;
					}
				}
			}
		}

		queue<int> que;
		vector<int> groupAns;
		for (int toGroup = 0; toGroup < numOfGroup; toGroup++) {
			if (groupInNum[toGroup] == 0) {
				que.push(toGroup);
				groupAns.push_back(toGroup);
			}
		}
		while (!que.empty()) {
			int fromGroup = que.front();
			que.pop();
			for (auto toGroup : groupDir[fromGroup]) {
				groupInNum[toGroup]--;
				if (groupInNum[toGroup] == 0) {
					que.push(toGroup);
					groupAns.push_back(toGroup);
				}
			}
		}
		if (groupAns.size() != numOfGroup)
			return {};

		vector<int> ans;
		for (auto groupId : groupAns) {
			auto& items = group2item[groupId];
			int tmpNumOfItem = 0;
			for (auto toItem : items) {
				if (itemInNum[toItem] == 0) {
					que.push(toItem);
					ans.push_back(toItem);
					tmpNumOfItem++;
				}
			}
			while (!que.empty()) {
				int fromItem = que.front();
				que.pop();
				for (auto toItem : itemDir[fromItem]) {
					itemInNum[toItem]--;
					if (itemInNum[toItem] == 0) {
						que.push(toItem);
						ans.push_back(toItem);
						tmpNumOfItem++;
					}
				}
			}
			if (tmpNumOfItem != items.size())
				return {};
		}
		return ans;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
