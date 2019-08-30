/*
https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca

题目描述
输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意:
在返回值的list中，数组长度大的数组靠前)
*/

#include <algorithm>
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
    void preOrder(TreeNode *node, int sum, vector<int> cur,
                  vector<vector<int>> &res) {
        cur.push_back(node->val);
        sum = sum - node->val;
        if (sum == 0 and !(node->left or node->right))
            res.push_back(cur);

        if (node->left != nullptr)
            preOrder(node->left, sum, cur, res);
        if (node->right != nullptr)
            preOrder(node->right, sum, cur, res);
    }

    vector<vector<int>> FindPath(TreeNode *root, int expectNumber) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        preOrder(root, expectNumber, vector<int>(), res);
        sort(res.begin(), res.end(),
             // lambda expression
             [](vector<int> x, vector<int> y) { return x.size() > y.size(); });
        return res;
    }
};
