#include<cstdio>
#include<cstring>
int main()
{
    int n, p, q, s, k, cnt, first;
    while(~scanf("%d", &n))
    {
        cnt = 0, first = 0;
        scanf("%d%d", &p, &q);
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d%d", &s, &k);
            if(s >= p && k >= q)
            {
                if(!first) first = i;
                ++cnt;
            }
        }
        printf("%d %d\n", cnt, first);
    }
    return 0;
}
