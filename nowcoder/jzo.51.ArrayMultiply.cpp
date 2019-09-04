/*
https://www.nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46

题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]
*...*A[n-1]。不能使用除法。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> multiply(const vector<int> &A) {
        vector<int> B(A.size(), 1);
        for (int i = 1; i < A.size(); ++i) {
            B[i] = B[i - 1] * A[i - 1];
        }

        int prod = 1;
        for (int i = B.size() - 2; i >= 0; --i) {
            prod *= A[i + 1];
            B[i] *= prod;
        }
        return B;
    }
};

// int main() {
//     auto res = Solution().multiply({1, 2, 3, 4, 5});
//     for (int x : res) {
//         cout << x << ' ';
//     }
//     cout << endl;
//     return 0;
// }
