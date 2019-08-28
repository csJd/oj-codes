/*
https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8

题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

class Solution {
  public:
    int NumberOf1(int n) {
        int ans = 0;
        while (n != 0) {
            n &= n - 1;
            ++ans;
        }
        return ans;
    }
};
