/*
https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2

题目描述
统计一个数字在排序数组中出现的次数。
*/

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
  public:
    int GetNumberOfK(vector<int> data, int k) {
        auto lb = lower_bound(data.begin(), data.end(), k);
        auto ub = upper_bound(data.begin(), data.end(), k);
        return ub - lb;
    }
};

// int main() {
//     printf("%d\n", Solution().GetNumberOfK({1, 1, 2, 3}, 1));
//     return 0;
// }
