/*
https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163

题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int length = numbers.size();
        int res = 0, cnt = 0;
        for (int num : numbers) {
            cnt += (num == res ? 1 : -1);
            if (cnt < 1) {
                cnt = 1;
                res = num;
            }
        }
        cnt = 0;
        for (int num : numbers)
            if (num == res)
                ++cnt;
        return (cnt > length / 2) ? res : 0;
    }
};

// int main() {
//     cout << Solution().MoreThanHalfNum_Solution({1, 2, 3, 2, 2, 2, 5, 4, 2})
//          << endl;
//     cout << Solution().MoreThanHalfNum_Solution({}) << endl;
//     return 0;
// }
