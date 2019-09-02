/*
https://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811

题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/

#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
  public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2) {
        set<int> numSet;
        for (int &num : data) {
            if (numSet.count(num) > 0) {
                numSet.erase(num);
            } else {
                numSet.insert(num);
            }
        }

        auto it = numSet.begin();
        *num1 = *(it++);
        *num2 = *(it);
    }
};

// int main() {
//     int a, b;
//     vector<int> arr = {1, 2, 1, 2, 3, 4};
//     Solution().FindNumsAppearOnce(arr, &a, &b);
//     cout << a << b << endl;

//     return 0;
// }
