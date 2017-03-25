#include <bits/stdc++.h>
using namespace std;
typedef struct TNode
{
    char data;
    TNode *lc, *rc;
} node, *BTree;

void build(BTree &t, string pre, string in)
{
    t = new node;
    t->lc = t->rc = NULL, t->data = pre[0];
    int k = in.find(pre[0]);
    if(k > 0) build(t->lc, pre.substr(1, k), in.substr(0, k));
    if(k < in.size() - 1) build(t->rc, pre.substr(k + 1), in.substr(k + 1));
}

void postTral(BTree &t)
{
    if(!t) return;
    postTral(t->lc);
    postTral(t->rc);
    putchar(t->data);
}

int main()
{
    string pre, in;
    while(cin >> pre >> in)
    {
        BTree t;
        build(t, pre, in);
        postTral(t);
        puts("");
    }
    return 0;
}
