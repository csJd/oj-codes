/*
https://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b

题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对
数字的和等于S，输出两个数的乘积最小的。

输出描述:
对应每个测试案例，输出两个数，小的先输出。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        int le = 0, ri = array.size() - 1;
        while (le < ri) {
            if (array[le] + array[ri] > sum)
                --ri;
            else if (array[le] + array[ri] < sum)
                ++le;
            else
                return {array[le], array[ri]};
        }
        return {};
    }
};

// int main() {
//     auto res = Solution().FindNumbersWithSum({1, 2, 3, 5}, 8);
//     for (int x : res) {
//         cout << x << ' ';
//     }
//     cout << endl;
//     return 0;
// }
