/*
https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e

题目描述
将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求不能使用字符
串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。

输入描述:
输入一个字符串,包括数字字母符号,可以为空

输出描述:
如果是合法的数值表达则返回该数字，否则返回0

+2147483647
2147483647

1a33
0
*/

#include <iostream>
using namespace std;

class Solution {
  public:
    int StrToInt(string str) {
        int res = 0;
        int sign = 1;
        if (str[0] == '-') {
            sign = -1;
            str[0] = '0';
        } else if (str[0] == '+') {
            str[0] = '0';
        }

        for (char x : str) {
            if (x < '0' or x > '9') {
                return 0;
            }
            res = res * 10 + sign * (x - '0');
        }
        return res;
    }
};

// int main() {
//     cout << Solution().StrToInt("-000002147483648") << endl;
//     return 0;
// }
