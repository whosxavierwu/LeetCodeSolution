// leetcode_1138.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string alphabetBoardPath(string target) {
		string result = "";
		int curRow = 0, curCol = 0;
		for (char w : target) {
			// find the position of w
			int tmpRow = (w - 'a') / 5;
			int tmpCol = (w - 'a') % 5;
			// from cur position to that pos
			int gapRow = tmpRow - curRow;
			int gapCol = tmpCol - curCol;
			// check if go col first 
			if (curRow * 5 + tmpCol <= 25) {
				result.insert(result.end(), abs(gapCol), gapCol > 0 ? 'R' : 'L');
				result.insert(result.end(), abs(gapRow), gapRow > 0 ? 'D' : 'U');
			}
			else {
				result.insert(result.end(), abs(gapRow), gapRow > 0 ? 'D' : 'U');
				result.insert(result.end(), abs(gapCol), gapCol > 0 ? 'R' : 'L');
			}			
			curRow = tmpRow;
			curCol = tmpCol;
			result += '!';
		}
		return result;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
