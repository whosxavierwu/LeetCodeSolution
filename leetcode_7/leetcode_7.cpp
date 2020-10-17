// https://leetcode.com/problems/reverse-integer/
#include <iostream>

class Solution {
public:
    int reverse(int x) {
        bool is_negative = (x < 0);
        long x_abs = abs(x);
        long result = 0;
        while (x_abs > 0) {
            int res = x_abs % 10;
            result = result * 10 + res;
            x_abs = x_abs / 10;
        }
        if (result > INT_MAX)
            result = 0;
        if (is_negative)
            result = -result;
        return int(result);
    }
    int reverse_v2(int x) {
        bool is_negative = (x < 0);
        int x_abs = abs(x);
        int result = 0;
        while (x_abs > 0) {
            int res = x_abs % 10;
            if (result > (INT_MAX - res) / 10) { 
                result = 0;
                break;
            }
            result = result * 10 + res;
            x_abs /= 10;
        }
        if (is_negative)
            result = -result;
        return result;
    }
};
