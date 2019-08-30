/*
https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf

题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        int length = input.size();
        if (length < k)
            return res;

        auto cmp = greater<int>();
        make_heap(input.begin(), input.end(), cmp);
        for (int i = 0; i < k; ++i) {
            pop_heap(input.begin(), input.end(), cmp);
            res.push_back(input.back());
            input.pop_back();
        }
        return res;
    }
};

// int main() {
//     for (int x :
//          Solution().GetLeastNumbers_Solution({4, 5, 1, 6, 2, 7, 3, 8}, 4))
//         cout << x << ' ';
//     cout << endl;

//     return 0;
// }
