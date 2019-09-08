// leetcode_5181.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/contest/weekly-contest-153/problems/distance-between-bus-stops/
/*
A bus has n stops numbered from 0 to n - 1 that form a circle. We know the distance between all pairs of neighboring stops where distance[i] is the distance between the stops number i and (i + 1) % n.

The bus goes along both directions i.e. clockwise and counterclockwise.

Return the shortest distance between the given start and destination stops.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
		if (destination < start) {
			int tmp = destination;
			destination = start;
			start = tmp;
		}
		else if (start == destination)
			return 0;
		int totalSum = 0;
		int partSum = 0;
		int len = distance.size();
		for (int i = 0; i < len; ++i) {
			totalSum += distance[i];
			if (i >= start && i < destination)
				partSum += distance[i];
		}
		return min(partSum, totalSum - partSum);
	}
};
int main()
{
	Solution sol;
	//vector<int> distance = { 1,2,3,4 };
	//cout << sol.distanceBetweenBusStops(distance, 0, 1) << endl;
	//cout << sol.distanceBetweenBusStops(distance, 0, 2) << endl;
	//cout << sol.distanceBetweenBusStops(distance, 0, 3) << endl;

	vector<int> distance = { 7, 10, 1, 12, 11, 14, 5, 0 };
	cout << sol.distanceBetweenBusStops(distance, 7, 2) << endl;
}
