/*
https://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e

题目描述
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，
同时包含指向父结点的指针。
*/

#include <cstdio>
using namespace std;

// struct TreeLinkNode {
//     int val;
//     struct TreeLinkNode *left;
//     struct TreeLinkNode *right;
//     struct TreeLinkNode *next;
//     TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
// };

class Solution {
  public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode) {
        TreeLinkNode *p = pNode;
        if (!p) {
            return p;
        }

        if (p->right == NULL) {
            // p is the right son of its parent
            while (p && p->next && p == p->next->right) {
                p = p->next;
            }
            p = p->next;
            return p;
        }

        p = p->right;
        while (p->left) {
            p = p->left;
        }
        return p;
    }
};
