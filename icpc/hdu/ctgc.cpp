#include<cstdio>
#include<cstring>
const int N = 1005;
int r[N], ans, n, m;
using namespace std;

int root(int a)
{
    while (r[a]!=a) a=r[a];
    return a;
}

void merge(int a, int b)
{
    int ra = root(a), rb = root(b);
    if(ra != rb) r[rb] = ra,--ans;
}

int main()
{
    int a, b;
    while(scanf("%d", &n),n)
    {
        scanf("%d",&m);
        for(int i = 1; i <= n; ++i)   r[i] = i;

        ans=n;
        while(m--)
        {
            scanf("%d%d", &a, &b);
            merge(a, b);
        }

        printf("%d\n", ans-1);
    }
    return 0;
}
