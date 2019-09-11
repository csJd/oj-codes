/*
https://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84

题目描述
请实现两个函数，分别用来序列化和反序列化二叉树

二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，从而使得内存中建立起来的二叉树可以持久保
存。序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过某种符号表示
空节点（#），以 ！ 表示一个结点值的结束（value!）。

二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。
*/

#include <cstdio>
#include <cstring>
#include <stack>
#include <string>

using namespace std;

// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
  public:
    char *Serialize(TreeNode *root) {
        string res = "";
        stack<TreeNode *> st;
        st.push(root);
        // use stack to perform preorder traverse
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            if (!node) {
                res += '#';
                continue;
            }
            res += to_string(node->val) + '!';
            st.push(node->right);
            st.push(node->left);
        }
        char *cres = new char[res.length() + 1];
        strcpy(cres, res.c_str());
        return cres;
    }

    TreeNode *MyDeserialize(char *str, int &pos) {
        if (str == nullptr || strlen(str + pos) == 0) {
            return nullptr;
        };
        if (str[pos] == '#') {
            pos += 1;
            return nullptr;
        }
        int val = atoi(str + pos);
        TreeNode *node = new TreeNode(val);
        pos = strchr(str + pos, '!') - str + 1;
        node->left = MyDeserialize(str, pos);
        node->right = MyDeserialize(str, pos);
        return node;
    }

    TreeNode *Deserialize(char *str) {
        int pos = 0;
        return MyDeserialize(str, pos);
    }
};

// int main() {
//     char stree[100] = "1!2!#3!###";
//     Solution solu;
//     TreeNode *root = solu.Deserialize(stree);
//     puts(solu.Serialize(root));
//     return 0;
// }
