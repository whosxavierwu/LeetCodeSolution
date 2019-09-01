// leetcode_985.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/sum-of-even-numbers-after-queries/
/*
We have an array A of integers, and an array queries of queries.

For the i-th query val = queries[i][0], index = queries[i][1], we add val to A[index].  
Then, the answer to the i-th query is the sum of the even values of A.

(Here, the given index = queries[i][1] is a 0-based index, and each query permanently modifies the array A.)

Return the answer to all queries.  Your answer array should have answer[i] as the answer to the i-th query.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
		// v1: 164 ms, faster than 49.07%
		vector<int> result;
		int sum = 0;
		for (int a : A) if (a % 2 == 0) sum += a;
		for (vector<int> query : queries) {
			int val = query[0];
			int index = query[1];
			int newVal = A[index] + val;
			if (A[index] % 2 == 0) sum -= A[index];
			if (newVal % 2 == 0) sum += newVal;
			A[index] = newVal;
			result.push_back(sum);
		}
		return result;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}
