// leetcode_347.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
// default priority_queue make the first element always be the greatest one
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		// v1: faster than 82.19%
		int len = nums.size();
		unordered_map<int, int> cntMap;
		for (int num : nums)
			cntMap[num]++;
		priority_queue<pair<int, int>> pq;  // pair: frequency and number
		vector<int> result;
		for (auto iter = cntMap.begin(); iter != cntMap.end(); ++iter) {
			pq.push(make_pair(iter->second, iter->first));
			if (pq.size() > cntMap.size() - k) {  // why?
				result.push_back(pq.top().second);
				pq.pop();
			}	
		}
		return result;

		// v2 faster than 39.57%
		// the greatest one is on the top
		//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		//unordered_map<int, int> cntMap;
		//for (int n : nums)
		//	cntMap[n]++;
		//for (auto iter = cntMap.begin(); iter != cntMap.end(); ++iter) {
		//	pq.push(make_pair(iter->second, iter->first));
		//	while (pq.size() > k)  // why?
		//		pq.pop();
		//}
		//vector<int> result;
		//while (!pq.empty()) {
		//	result.push_back(pq.top().second);
		//	pq.pop();
		//}
		//return result;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
