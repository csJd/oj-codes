/*
https://www.nowcoder.com/practice/445c44d982d04483b04a54f298796288

题目描述
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
*/

#include <queue>
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
        TreeNode *p;
        vector<int> row;
        queue<tuple<TreeNode *, int>> q;
        q.push(make_tuple(pRoot, 0));
        int curLevel = 0, level;
        while (!q.empty()) {
            tie(p, level) = q.front();
            q.pop();
            if (level > curLevel) {
                curLevel = level;
                res.push_back(row);
                row.clear();
            }
            row.push_back(p->val);
            if (p->left) {
                q.push(make_tuple(p->left, level + 1));
            }
            if (p->right) {
                q.push(make_tuple(p->right, level + 1));
            }
        }
        res.push_back(row);
        return res;
    }
};
