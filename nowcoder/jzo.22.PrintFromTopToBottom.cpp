/*
https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701

题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/

#include <queue>
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
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            res.push_back(cur->val);
            if (cur->left != nullptr)
                q.push(cur->left);
            if (cur->right != nullptr)
                q.push(cur->right);
        }
        return res;
    }
};
