/*
https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1

题目描述
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流
中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用GetMedian()
方法获取当前读取数据的中位数。
*/

#include <queue>
using namespace std;

class Solution {
  public:
    priority_queue<int> left;                             // maximum at top
    priority_queue<int, vector<int>, greater<int>> right; // minimum at top

    void Insert(int num) {
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double GetMedian() {
        if (left.size() > right.size()) {
            return left.top();
        }
        return (left.top() + right.top()) / 2.0;
    }
};
