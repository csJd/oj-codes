/*
https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593

题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

#include <vector>
using namespace std;

class Solution {
  public:
    void reOrderArray(vector<int> &array) {
        int le = 0, ri = 0, length = array.size();
        vector<int> nums;
        vector<int> evens;

        for (int x : array) {
            if (x % 2 == 1) {
                nums.push_back(x);
            } else {
                evens.push_back(x);
            }
        }
        nums.insert(nums.end(), evens.begin(), evens.end());
        array.assign(nums.begin(), nums.end());
    }

    // // if no order limit
    // void reOrderArray(vector<int>& array) {
    //     int le = 0, ri = array.size() - 1;
    //     while (le < ri) {
    //         if (array[le] % 2 == 1) {
    //             ++le;
    //         } else if (array[ri] % 2 == 0) {
    //             --ri;
    //         } else {
    //             swap(array[le++], array[ri--]);
    //         }
    //     }
    // }
};
