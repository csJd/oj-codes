/*
https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5

题目描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。
即输出P%1000000007

输入描述:
题目保证输入的数组中没有的相同的数字

数据范围：
    对于%50的数据,size<=10^4
    对于%75的数据,size<=10^5
    对于%100的数据,size<=2*10^5

示例1
输入
1,2,3,4,5,6,7,0

输出
7
*/

#include <cstdio>
#include <vector>
using namespace std;

const int MOD = 1000000007;

class Solution {
  public:
    vector<int> merge(vector<int> &a, vector<int> &b, int &cnt) {
        int i = 0, j = 0, la = a.size(), lb = b.size();
        vector<int> res;
        while (i < la || j < lb) {
            if (j >= lb || (i < la && a[i] <= b[j])) {
                res.push_back(a[i++]);
            } else {
                cnt = (cnt + la - i) % MOD;
                res.push_back(b[j++]);
            }
        }
        return res;
    }

    vector<int> mergeSort(vector<int> data, int &cnt) {
        if (data.size() <= 1)
            return data;
        int mid = data.size() / 2;
        vector<int> left =
            mergeSort(vector<int>(data.begin(), data.begin() + mid), cnt);
        vector<int> right =
            mergeSort(vector<int>(data.begin() + mid, data.end()), cnt);
        return merge(left, right, cnt);
    }

    int InversePairs(vector<int> data) {
        int ans = 0;
        mergeSort(data, ans);
        return ans;
    }
};

// int main() {
//     printf("%d\n", Solution().InversePairs({1, 2, 1}));
//     printf("%d\n", Solution().InversePairs({1, 2, 3, 4, 5, 6, 7, 0}));
//     return 0;
// }
