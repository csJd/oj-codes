#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;
const int maxn = 10005, INF = 0x3f3f3f3f;
int in[maxn], post[maxn], msum, ans;

struct node
{
    int val;
    node *left, *right;
    node(): left(NULL), right(NULL) {}
};

node* build(int le, int ri, int pos)
{
    node *cur = new node;
    cur->val = post[pos];
    if(le == ri) return cur;
    int i = le;
    while(in[i] != post[pos]) ++i;
    if(i == le) cur->left = NULL;
    else  cur->left = build(le, i - 1, pos - 1 - (ri - i));
    if(i == ri) cur->right = NULL;
    else cur->right = build(i + 1, ri, pos - 1);
    return cur;
}

void dfs(node *cur, int sum)
{
    int t = cur->val;
    if(!(cur->left || cur->right))
    {
        if(sum + t < msum || (sum + t == msum && t < ans))
            msum = sum + t, ans = t;
    }
    if(cur->left != NULL) dfs(cur->left, sum + t);
    if(cur->right != NULL) dfs(cur->right, sum + t);

}

int main()
{
    char s[maxn*10];
    while(gets(s) != NULL)
    {
        int t = 0, l = 0;
        for(int i = 0; s[i] != '\0'; ++i)
            if(isdigit(s[i])) t = t * 10 + s[i] - '0';
            else  in[++l] = t, t = 0;
        in[++l] = t;

        gets(s);
        l = t = 0;
        for(int i = 0; s[i] != '\0'; ++i)
            if(isdigit(s[i])) t = t * 10 + s[i] - '0';
            else post[++l] = t, t = 0;
        post[++l] = t;

        node *root = build(1, l, l);
        ans = msum = INF;
        dfs(root, 0);
        printf("%d\n", ans);
    }
    return 0;
}
