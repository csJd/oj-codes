/*
https://www.nowcoder.com/practice/ef068f602dde4d28aab2b210e859150a

题目描述
给定一棵二叉搜索树，请找出其中的第k小的结点。例如，（5，3，7，2，4，6，8）中，
按结点数值大小顺序第三小结点的值为4。
*/

#include <stack>

using namespace std;

// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
  public:
    TreeNode *KthNode(TreeNode *pRoot, int k) {
        stack<TreeNode *> st;
        TreeNode *p = pRoot;
        // use stack to perform in-order traverse
        while (p || !st.empty()) {
            // only node without a left child can be poped
            while (p) {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();

            --k;
            if (k == 0) {
                return p;
            }
            p = p->right;
        }

        return nullptr;
    }
};
