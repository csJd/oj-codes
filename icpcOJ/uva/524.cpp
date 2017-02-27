#include<cstdio>
using namespace std;
const int N = 50;
int p[N], vis[N], a[N], n;

int isPrime(int k)
{
    for(int i = 2; i * i <= k; ++i)
        if(k % i == 0) return 0;
    return 1;
}

void dfs(int cur)
{
    if(cur == n && p[a[n - 1] + 1])
    {
        printf("%d", a[0]);
        for(int i = 1; i < n; ++i)
            printf(" %d", a[i]);
        printf("\n");
    }

    for(int i = 2; cur < n && i <= n; ++i)
    {
        if(!vis[i] && p[a[cur - 1] + i])
        {
            vis[i] = a[cur] = i;
            dfs(cur + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    int cas = 0;
    a[0] = 1;
    for(int i = 2; i < N; ++i)
        p[i] = isPrime(i);

    while(~scanf("%d", &n))
    {
        if(cas) printf("\n");
        printf("Case %d:\n", ++cas);
        dfs(1);
    }

    return 0;
}
