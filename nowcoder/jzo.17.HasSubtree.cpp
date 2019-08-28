/*
https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88

题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/

// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
  public:
    bool isSubtree(TreeNode *r1, TreeNode *r2) {
        if (r2 == nullptr)
            return true;
        if (r1 == nullptr or r1->val != r2->val)
            return false;
        return isSubtree(r1->left, r2->left) and
               isSubtree(r1->right, r2->right);
    }

    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
        if (pRoot1 == nullptr or pRoot2 == nullptr)
            return false;
        return isSubtree(pRoot1, pRoot2) or HasSubtree(pRoot1->left, pRoot2) or
               HasSubtree(pRoot1->right, pRoot2);
    }
};
