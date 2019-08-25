// leetcode_1169.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
A transaction is possibly invalid if:
the amount exceeds $1000, or;
if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <set>
using namespace std;

class Solution {
public:
	vector<string> invalidTransactions(vector<string>& transactions) {
		vector<int> offsets(3);
		set<string> result;
		int numOfTrans = transactions.size();
		for (int i = 0; i < numOfTrans; ++i) {
			for (int k = 0, pos = 0; k < 3; ++k) {
				offsets[k] = transactions[i].find(',', pos);
				pos = offsets[k] + 1;
			}
			string name_i = transactions[i].substr(0, offsets[0]);
			int time_i = stoi(transactions[i].substr(offsets[0] + 1, offsets[1] - offsets[0]));
			int amount_i = stoi(transactions[i].substr(offsets[1] + 1, offsets[2] - offsets[1]));
			string city_i = transactions[i].substr(offsets[2] + 1, transactions[i].length() - offsets[2] - 1);

			bool mark = false;
			if (amount_i > 1000) {
				result.insert(transactions[i]);
				mark = true;
			} 

			for (int j = i + 1; j < numOfTrans; ++j) {
				for (int k = 0, pos = 0; k < 3; ++k) {
					offsets[k] = transactions[j].find(',', pos);
					pos = offsets[k] + 1;
				}
				string name_j = transactions[j].substr(0, offsets[0]);
				int time_j = stoi(transactions[j].substr(offsets[0] + 1, offsets[1] - offsets[0]));
				int amount_j = stoi(transactions[j].substr(offsets[1] + 1, offsets[2] - offsets[1]));
				string city_j = transactions[j].substr(offsets[2] + 1, transactions[j].length() - offsets[2] - 1);

				if (name_i==name_j && city_i!= city_j && abs(time_i - time_j) <= 60) {
					result.insert(transactions[j]);
					if (!mark) {
						result.insert(transactions[i]);
						mark = true;
					}
				} 
			}
		}
		vector<string> fin;
		fin.assign(result.begin(), result.end());
		return fin;
	}
};

int main()
{
	Solution sol;
	//vector<string> trans = { "alice,20,800,mtv","alice,50,100,beijing" };
	//vector<string> trans = { "alice,20,800,mtv","bob,50,1200,mtv" };
	vector<string> trans = { "alice,20,800,mtv","alice,50,1200,mtv" };
	vector<string> result = sol.invalidTransactions(trans);
	for (string s : result)
		cout << s << endl;
}
