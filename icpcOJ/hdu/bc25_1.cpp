#include<cstdio>
#include<cstring>
using namespace std;
const int N = 105;
int e[N][N], v[N];
int n, m;

bool dfs(int k)
{
    if(v[k]) return false;
    v[k] = 1;
    for(int i = 1; i <= n; ++i)
        if(e[k][i])
            if(!dfs(i))  return false;
    return true;
}

int main()
{
    int a, b, i;
    while(~scanf("%d%d", &n, &m))
    {
        memset(e, 0, sizeof(e));
        while(m--)
        {
            scanf("%d %d", &a, &b);
            e[a][b] = 1;
        }
        for(i = 1; i <= n; ++i)
        {
            memset(v, 0, sizeof(v));
            if(!dfs(i)) break;
        }
        if(i > n) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
