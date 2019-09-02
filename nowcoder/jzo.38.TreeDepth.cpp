/*
https://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b

题目描述
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
*/

// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
  public:
    int TreeDepth(TreeNode *pRoot) {
        if (pRoot == nullptr) {
            return 0;
        }
        return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
    }
};
