// leetcode_399.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/evaluate-division/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		// v1: faster than 63.55%, less than 100.00% 
		unordered_map<string, pair<int, double>> variables;
		int groupId = 0;
		for (int i = 0; i < equations.size(); ++i) {
			string a = equations[i][0], b = equations[i][1];
			double value = values[i];
			// store values of variables
			auto iter1 = variables.find(a);
			auto iter2 = variables.find(b);
			if (iter1 == variables.end() && iter2 == variables.end()) {
				variables[a] = make_pair(groupId, value);
				variables[b] = make_pair(groupId, 1.0);
				groupId++;
			}
			else if (iter1 == variables.end()) {
				variables[a] = make_pair(iter2->second.first, iter2->second.second * value);
			}
			else if (iter2 == variables.end()) {
				variables[b] = make_pair(iter1->second.first, iter1->second.second / value);
			}
			else if (iter1->second.first != iter2->second.first) {
				// merge two group, reset b's group
				int group1 = iter1->second.first, group2 = iter2->second.first;
				// a/b=v, b1=a/v, coef=b1/b, group(b)*coef
				double coef = (iter1->second.second / value) / iter2->second.second;
				for (auto iter = variables.begin(); iter != variables.end(); ++iter) {
					if (iter->second.first == group2) {
						iter->second.first = group1;
						iter->second.second = iter->second.second * coef;
					}
				}
			}
		}
		vector<double> result;
		for (vector<string>& query : queries) {
			string a = query[0], b = query[1];
			double tmpRes = 0.0;
			if (variables.find(a) == variables.end() 
				|| variables.find(b) == variables.end() 
				|| variables[a].first != variables[b].first) {
				tmpRes = -1.0;
			}
			else {
				tmpRes = variables[a].second / variables[b].second;
			}
			result.push_back(tmpRes);
		}
		return result;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}

