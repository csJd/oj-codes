#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

struct Agency
{
    char name[20];
    int a, b, cost;
    bool operator< (const Agency &c) const
    {
        if(cost == c.cost) return strcmp(name, c.name) < 0;
        return cost < c.cost;
    }
} ag[N];

int getCost(int n, int m, int a, int b)
{
    int ret = 0;
    while(n > m)
    {
        if(n / 2 >= m && (n - n / 2) * a > b)
            n = n / 2, ret += b;
        else --n, ret += a;
    }
    return ret;
}

int main()
{
    int T, n, m, l, cas = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &l);
        for(int i = 0; i < l; ++i)
        {
            scanf(" %[^:]:%d,%d", ag[i].name, &ag[i].a, &ag[i].b);
            ag[i].cost = getCost(n, m, ag[i].a, ag[i].b);
        }
        sort(ag, ag + l);
        printf("Case %d\n", ++cas);
        for(int i = 0; i < l; ++i)
            printf("%s %d\n", ag[i].name, ag[i].cost);
    }

    return 0;
}
//Last modified :  2015-08-19 08:27 CST

