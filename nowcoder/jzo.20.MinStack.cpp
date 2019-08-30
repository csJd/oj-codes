/*
https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/

#include <stack>
using namespace std;

class Solution {
  public:
    stack<int> data;
    stack<int> minv;

    void push(int value) {
        data.push(value);
        if (minv.empty() or value < minv.top())
            minv.push(value);
        else
            minv.push(minv.top());
    }
    void pop() {
        data.pop();
        minv.pop();
    }
    int top() { return data.top(); }
    int min() { return minv.top(); }
};
