/*
https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec

题目描述
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个
指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符
序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，
搞定它！
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    void reverseString(string &s, int i, int j) {
        while (i < j) {
            swap(s[i++], s[j--]);
        }
    }
    string LeftRotateString(string str, int n) {
        int length = str.size();
        if (length == 0) {
            return str;
        }
        n = n % length;
        reverseString(str, 0, n - 1);
        reverseString(str, n, length - 1);
        reverseString(str, 0, length - 1);
        return str;
    }
};

// int main() {
//     string res = Solution().LeftRotateString("abcXYZdef", 3);
//     cout << res << endl;
//     return 0;
// }
