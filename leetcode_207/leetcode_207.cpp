// leetcode_207.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/course-schedule/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool acyclic(vector<vector<int>>& g, vector<bool>& todo, vector<bool>& done, int node) {
		if (todo[node]) return false;
		if (done[node]) return true;
		todo[node] = done[node] = true;
		for (int v : g[node]) {
			if (!acyclic(g, todo, done, v))
				return false;
		}
		todo[node] = false;
		return true;
	}
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		// v1: BFS: 28 ms, faster than 41.08%
		//vector<vector<int>> subCourses(numCourses);
		//vector<int> numOfParents(numCourses);
		//for (auto p : prerequisites) {
		//	subCourses[p[1]].push_back(p[0]);
		//	numOfParents[p[0]]++;
		//}
		//	
		//for (int i = 0; i < numCourses; ++i) {
		//	bool haveCourseToLearn = false;
		//	int curCourse = -1;
		//	for (int j = 0; j < numCourses; ++j) {
		//		if (numOfParents[j] == 0) {
		//			haveCourseToLearn = true;
		//			curCourse = j;
		//			break;
		//		}
		//	}
		//	if (!haveCourseToLearn)
		//		return false;
		//	numOfParents[curCourse]--;
		//	for (int subCourse : subCourses[curCourse])
		//		numOfParents[subCourse]--;
		//}
		//return true;

		// v2: DFS   16 ms, faster than 97.19% 
		vector<vector<int>> subCourses(numCourses);
		for (auto p : prerequisites) {
			subCourses[p[1]].push_back(p[0]);
		}
		vector<bool> todo(numCourses, false);
		vector<bool> done(numCourses, false);
		for (int i = 0; i < numCourses; ++i) {
			if (!done[i] && !acyclic(subCourses, todo, done, i))
				return false;
		}
		return true;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}
