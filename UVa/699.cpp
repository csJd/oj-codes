#include<cstdio>
#include<cstring>
using namespace std;
int le, ri;
const int M = 205;
int a[M];

void build(int p)
{
    int t;
    scanf("%d", &t);
    if(t == -1) return;
    else
    {
        a[p] += t;
        build(p - 1);
        build(p + 1);
        le = le < p ? le : p;
        ri = ri > p ? ri : p;
    }
}

int main()
{
    int cas = 0;
    le = M, ri = 0;
    build(M / 2);

    while(le <= ri)
    {
        printf("Case %d:\n", ++cas);
        for(int i = le; i < ri; ++i)
            printf("%d ", a[i]);
        printf("%d\n\n", a[ri]);

        memset(a, 0, sizeof(a));
        le = M, ri = 0;
        build(M / 2);
    }
    return 0;
}
