/*
https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00

题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
保证base和exponent不同时为0
*/

class Solution {
  public:
    double Power(double base, int exponent) {
        if (base == 0) {
            return 0;
        }
        if (exponent < 0) {
            base = 1 / base;
            exponent = -exponent;
        }

        double ans = 1;
        while (exponent) {
            if (exponent & 1) {
                ans *= base;
            }
            exponent >>= 1;
            base *= base;
        }
        return ans;
    }
};
