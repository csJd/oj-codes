/*
https://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb

题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/

// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
  public:
    bool preOrder(TreeNode *p1, TreeNode *p2) {
        if (p1 == nullptr || p2 == nullptr) {
            return p1 == p2;
        }
        if (p1->val != p2->val) {
            return false;
        }
        return preOrder(p1->left, p2->right) && preOrder(p2->left, p1->right);
    }
    bool isSymmetrical(TreeNode *pRoot) {
        TreeNode *p1 = pRoot, *p2 = pRoot;
        return preOrder(p1, p2);
    }
};
