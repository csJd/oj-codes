/*
https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/

class Solution {
public:
    int jumpFloor(int number) {
        int fib[number+1];
        fib[0] = fib[1] = 1;
        for(int i = 2; i<=number; ++i){
            fib[i] = fib[i-1] + fib[i-2];
        }
        return fib[number];
    }
};
