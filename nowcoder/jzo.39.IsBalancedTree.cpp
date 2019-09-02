/*
https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222

题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/

class Solution {
  public:
    int getDeepth(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        int leftDepth = getDeepth(node->left);
        int rightDepth = getDeepth(node->right);
        if (leftDepth < 0 || rightDepth < 0)
            return -1;
        if (leftDepth - rightDepth < -1 || leftDepth - rightDepth > 1)
            return -1;
        return max(leftDepth, rightDepth) + 1;
    }

    bool IsBalanced_Solution(TreeNode *pRoot) { return getDeepth(pRoot) >= 0; }
};
