// leetcode_406.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/queue-reconstruction-by-height/
/*
 (h, k), where h is the height of the person 
 and k is the number of people in front of this person who have a height greater than or equal to h.
Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	static bool funcLeft2Right(vector<int> p1, vector<int> p2) {
		// from tall to short
		return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
	}
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		// v1: faster than 5.68% 
		//sort(people.begin(), people.end(), [](vector<int> p1, vector<int> p2) {
		//	return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
		//});
		//vector<vector<int>> sol;
		//for (vector<int> person : people) {
		//	sol.insert(sol.begin() + person[1], person);
		//}
		//return sol;

		// v2 faster than 5.56% 
		sort(people.begin(), people.end(), funcLeft2Right);
		vector<vector<int>> result;
		for (vector<int> p : people) {
			result.insert(result.begin() + p[1], p);
		}
		return result;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}
