// 给定一个二叉树 Node* root，请深度遍历判断是否完全二叉树?

struct Node {
    int val;
    Node *left;
    Node *right;
};

int countNodes(Node *root) {
    if (root == nullptr)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool check(Node *root, int index, int &count) {
    if (root == nullptr)
        return true;
    if (index >= count)
        return false;
    return check(root->left, index * 2 + 1, count) &&
           check(root->right, index * 2 + 2, count);
}

// hint: 完全二叉树按层次从左到右编号的话（从 0 开始）所有的结点编号均满足：
// 左孩子编号 = i*2+1，右孩子编号 = i*2+2
bool isCompleteTree(Node *root) {
    int count = countNodes(root);
    return check(root, 0, count);
}
