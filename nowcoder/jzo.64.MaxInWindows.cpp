/*
https://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788

题目描述
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}；
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2, 3,4],2,6,2,5,1}，
{2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}，
{2,3,4,2,[6,2,5], 1}， {2,3,4,2,6,[2,5,1]}。

单调队列: https://oi-wiki.org/ds/monotonous-queue
*/

#include <deque>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> maxInWindows(const vector<int> &num, unsigned int size) {
        vector<int> res;
        if (size == 0) {
            return res;
        }

        deque<int> mono_queue; // decreasing monotonous queue
        for (unsigned i = 0; i < num.size(); ++i) {
            // keep nums decreasing in queue
            while (!mono_queue.empty() && num[i] >= num[mono_queue.back()]) {
                mono_queue.pop_back();
            }
            mono_queue.push_back(i);
            if (i + 1 >= size) {
                // front num of queue is out of window
                if (i - mono_queue.front() >= size) {
                    mono_queue.pop_front();
                }
                res.push_back(num[mono_queue.front()]);
            }
        }
        return res;
    }
};

// int main() {
//     unsigned int size = 3u;
//     auto res = Solution().maxInWindows({2, 3, 4, 2, 6, 2, 5, 1}, size);
//     for (int x : res) {
//         cout << x << ' ';
//     }
//     cout << endl;
//     return 0;
// }
