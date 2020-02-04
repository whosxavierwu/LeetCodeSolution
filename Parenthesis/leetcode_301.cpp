// leetcode_301.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/remove-invalid-parentheses/
/*
Remove the minimum number of invalid parentheses in order to make the input string valid. 
Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Example 1:

Input: "()())()"
Output: ["()()()", "(())()"]
Example 2:

Input: "(a)())()"
Output: ["(a)()()", "(a())()"]
Example 3:

Input: ")("
Output: [""]
*/
#include <iostream>
#include <vector>
#include <string> 
#include <stack>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

class Solution {
public:
    void dfs(int p, int lastRm, string dir, string s, vector<string> &result) {
        for (int i = p, count = 0; i < s.size(); ++i) {
            if (s[i] == dir[0])
                ++count;
            else if (s[i] == dir[1])
                --count;
            if (count >= 0)
                continue;
            for (int j = lastRm; j <= i; ++j)
                if (s[j] == dir[1] && (j == lastRm || s[j - 1] != dir[1]))
                    dfs(i, j, dir, s.substr(0, j) + s.substr(j + 1), result);
            return;
        }
        reverse(s.begin(), s.end());
        if (dir[0] == '(')
            dfs(0, 0, ")(", s, result);
        else
            result.push_back(s);
    }
    vector<string> removeInvalidParentheses(string s) {
        // v1: BFS 8 ms, faster than 78.22% 
        //vector<string> results;
        //queue<tuple<string, int, int, char>> q;
        //q.push(make_tuple(s, 0, 0, '('));
        //while (!q.empty()) {
        //    auto t = q.front(); 
        //    q.pop();
        //    string str = get<0>(t);
        //    int start = get<1>(t);
        //    int lastRm = get<2>(t);
        //    char left = get<3>(t);
        //    char right = (left == '(') ? ')' : '(';
        //    int count = 0;
        //    for (int i = start; i < str.size(); ++i) {
        //        if (str[i] == left)
        //            ++count;
        //        else if (str[i] == right)
        //            --count;
        //        if (count >= 0)
        //            continue;
        //        for (int j = lastRm; j <= i; ++j)
        //            if (str[j] == right && (j == lastRm || str[j - 1] != right))
        //                q.push(make_tuple(str.substr(0, j) + str.substr(j + 1), i, j, left));
        //        break;
        //    }
        //    if (count < 0)
        //        continue;
        //    reverse(str.begin(), str.end());
        //    if (left == '(')
        //        q.push(make_tuple(str, 0, 0, ')'));
        //    else
        //        results.push_back(str);
        //}
        //return results;

        // v2 dfs 4 ms, faster than 94.12%
        vector<string> results;
        dfs(0, 0, "()", s, results);
        return results;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

