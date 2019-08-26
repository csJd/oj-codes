/*
题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

#include <vector>
#include <stack>
using namespace std;

// Definition for binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &pre, vector<int> &vin, int ls, int le, int rs, int re)
    {
        if (ls >= le)
        {
            return NULL;
        }
        TreeNode *node = new TreeNode(pre[ls]);  // cannot be `TreeNode node(pre[ls])`
        int pos;
        for (pos = rs; vin[pos] != pre[ls]; ++pos) {}
        int length = pos - rs;
        node->left = buildTree(pre, vin, ls + 1, ls + length + 1, rs, rs + length);
        node->right = buildTree(pre, vin, ls + length + 1, le, rs + length + 1, re);
        return node;
    }

    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        return buildTree(pre, vin, 0, pre.size(), 0, pre.size());
    }
};
