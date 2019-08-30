/*
https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd1

题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    bool valid(vector<int>::iterator inBegin, vector<int>::iterator inEnd,
               vector<int>::iterator postBegin, vector<int>::iterator postEnd) {
        if (inEnd - inBegin != postEnd - postBegin)
            return false;
        if (inBegin == inEnd)
            return true;
        auto leftEnd = lower_bound(inBegin, inEnd, *(postEnd - 1));
        if (leftEnd == inEnd)
            return false;
        int leftLen = leftEnd - inBegin;
        return valid(inBegin, leftEnd, postBegin, postBegin + leftLen) &&
               valid(leftEnd + 1, inEnd, postBegin + leftLen, postEnd - 1);
    }

    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty())
            return false;
        vector<int> inOrder(sequence);
        sort(inOrder.begin(), inOrder.end());
        return valid(inOrder.begin(), inOrder.end(), sequence.begin(),
                     sequence.end());
    }
};

// int main() {
//     cout << Solution().VerifySquenceOfBST({1, 2, 3}) << endl;
//     cout << Solution().VerifySquenceOfBST({3, 1, 2}) << endl;
//     return 0;
// }
