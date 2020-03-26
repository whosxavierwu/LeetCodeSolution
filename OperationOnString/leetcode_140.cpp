// https://leetcode.com/problems/word-break-ii/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <stack>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // 8 ms, faster than 95.08%
        unordered_set<string> wordSet;
        int maxLen = 0;
        for (string& word : wordDict) {
            wordSet.insert(word);
            if (word.length() > maxLen)
                maxLen = word.length();
        }
        int N = s.length();
        vector<vector<int>> mem(N + 1);
        vector<bool> isGoodString(N + 1, false);
        isGoodString[0] = true;
        for (int len = 1; len <= N; ++len) {
            for (int prevLen = len - 1; prevLen >= 0 && (len - prevLen) <= maxLen; --prevLen) {
                if (isGoodString[prevLen] && wordSet.find(s.substr(prevLen, len - prevLen)) != wordSet.end()) {
                    isGoodString[len] = true;
                    mem[len].push_back(prevLen);
                }
            }
        }
        if (!isGoodString[N])
            return {};
        vector<string> result;
        stack<pair<int, string>> sta;
        sta.push({ N, "" });
        while (!sta.empty()) {
            int len = sta.top().first;
            string sentence = sta.top().second;
            sta.pop();
            if (len == 0)
                result.push_back(sentence);
            for (int prevLen : mem[len]) {
                string tmp = (sentence != "") ? " " : "";
                sta.push({ prevLen, s.substr(prevLen, len - prevLen) + tmp + sentence });
            }
        }
        return result;
    }
};
