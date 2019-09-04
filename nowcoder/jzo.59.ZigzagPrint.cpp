/*
https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0

题目描述
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的
顺序打印，其他行以此类推。
*/

#include <algorithm>
#include <deque>
#include <tuple>
#include <vector>
using namespace std;

// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
  public:
    vector<vector<int>> Print(TreeNode *pRoot) {
        vector<vector<int>> res;
        if (!pRoot) {
            return res;
        }
        vector<int> row;
        TreeNode *p;
        deque<tuple<TreeNode *, int>> q;
        q.push_back(make_tuple(pRoot, 0));
        int curLevel = 0, level;
        while (!q.empty()) {
            tie(p, level) = q.front();
            q.pop_front();
            if (level > curLevel) {
                if (curLevel % 2) {
                    reverse(row.begin(), row.end());
                }
                res.push_back(row);
                row.clear();
                curLevel = level;
            }
            row.push_back(p->val);
            if (p->left) {
                q.push_back(make_tuple(p->left, level + 1));
            }
            if (p->right) {
                q.push_back(make_tuple(p->right, level + 1));
            }
        }
        if (curLevel % 2) {
            reverse(row.begin(), row.end());
        }
        res.push_back(row);
        return res;
    }
};
