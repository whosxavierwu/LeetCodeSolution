// leetcode_5123.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://leetcode.com/contest/biweekly-contest-15/problems/iterator-for-combination/ 
/*
Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
A function next() that returns the next combination of length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if there exists a next combination.


Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false


Constraints:

1 <= combinationLength <= characters.length <= 15
There will be at most 10^4 function calls per test.
It's guaranteed that all calls of the function next are valid.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class CombinationIterator {
    int l, n;
    string s, cur;
public:
    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        n = s.size();
        l = combinationLength;
        cur = "";
    }

    string next() {
        if (cur.empty())
            cur = s.substr(0, l);
        else {
            for (int i = l - 1, j = n - 1; i >= 0; i--, j--) {
                if (cur[i] != s[j]) {
                    auto it = upper_bound(s.begin(), s.end(), cur[i]);
                    int pos = distance(s.begin(), it);
                    while (i < n)
                        cur[i++] = s[pos++];
                    break;
                }
            }
        }
        return cur;
    }

    bool hasNext() {
        return cur != s.substr(n - l);
    }
};



/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
int main()
{
    std::cout << "Hello World!\n";
}
