/*
https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1

题目描述
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/

#include <iostream>
using namespace std;

class Solution {
  public:
    int Add(int num1, int num2) {
        int a, b, c = 0;
        int ans = 0;
        // 1 << 31 == INT_MIN, INT_MIN << 1 == 0;
        for (int base = 1 << 0; base != 0; base <<= 1) {
            a = base & num1;
            b = base & num2;
            if (a ^ b ^ c) { // c for carry bit
                ans |= base;
            }
            c = ((a & b) | ((a | b) & (c))) << 1;
        }
        return ans;
    }
};

// int main() {
//     int res = Solution().Add(2, 3);
//     cout << res << endl;
//     return 0;
// }
