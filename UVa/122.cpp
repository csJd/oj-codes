#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;
const int maxn = 300;

char s[maxn][maxn];
int t, n, lans;
bool comp;

struct Node
{
    int data;
    Node* left, *right;
    bool have;
    Node(): left(NULL), right(NULL), have(false) {};
};

Node *ans[maxn];

bool bfs(Node* root)
{
    int fro = 0, bac = 0;
    ans[fro] = root;
    while(fro <= bac)
    {
        if(!ans[fro]->have) return false;
        if(ans[fro]->left != NULL) ans[++bac] = ans[fro]->left;
        if(ans[fro]->right != NULL) ans[++bac] = ans[fro]->right;
        ++fro;
    }
    lans = bac;
    return true;
}

int main()
{
    while(~scanf("%s", s[0]))
    {
        n = 0;
        Node root, *cur = &root;
        comp = true;
        do
        {
            t = 0;
            int l = strlen(s[n]);
            for(int i = 1; i < l; ++i)
            {
                if(isdigit(s[n][i]))
                {
                    t = t * 10 + s[n][i] - '0';
                }
                else if(s[n][i] == 'L')
                {
                    if(cur->left == NULL)
                        cur->left = new Node;
                    cur = cur->left;
                }
                else if(s[n][i] == 'R')
                {
                    if(cur->right == NULL)
                        cur->right = new Node;
                    cur = cur->right;
                }
            }
            if(cur->have) comp = false;
            else
            {
                cur->data = t;
                cur->have = true;
            }
            cur = &root;
        }
        while(scanf("%s", s[++n]), s[n][1] != ')');

        if(comp) comp = bfs(&root);
        if(comp)
        {
            for(int i = 0; i < lans; ++i)
                printf("%d ", ans[i]->data);
            printf("%d\n", ans[lans]->data);
        }
        else printf("not complete\n");
    }
    return 0;
}
