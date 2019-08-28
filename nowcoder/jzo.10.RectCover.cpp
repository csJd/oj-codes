/*
https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6

题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

class Solution {
  public:
    int rectCover(int number) {
        int fib[number + 2];
        fib[0] = fib[1] = 1;
        for (int i = 2; i <= number; ++i) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        fib[0] = 0;
        return fib[number];
    }
};
