/*
https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5

题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/

#include <stack>
using namespace std;

// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
  public:
    TreeNode *Convert(TreeNode *pRootOfTree) {
        if (pRootOfTree == nullptr) {
            return pRootOfTree;
        }

        stack<TreeNode *> st;
        TreeNode *last = nullptr;
        TreeNode *head;

        // in-order traversal
        st.push(pRootOfTree);
        while (!st.empty()) {
            TreeNode *p = st.top();
            // left
            if (p->left != nullptr) {
                st.push(p->left);
                p->left = nullptr;
                continue;
            }

            // current
            st.pop();
            p->left = last;
            if (last != nullptr)
                last->right = p;
            else
                head = p;
            last = p;

            // right
            if (p->right != nullptr) {
                st.push(p->right);
            }
        }

        return head;
    }
};
