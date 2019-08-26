/*
https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3

题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
*/
class Solution {
public:
    int Fibonacci(int n) {
        int fib[40] = {0, 1, 1};
        for(int i = 3; i<=n; ++i){
            fib[i] = fib[i-1] + fib[i-2];
        }
        return fib[n];
    }
};
