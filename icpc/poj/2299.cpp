#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 500005;
int a[N], r[N], n;

bool cmp(int i, int j) //离散化排序用的比较函数
{
    return a[i] < a[j];
}

void add(int x, int v)
{
    while(x <= n)
    {
        a[x] += v;
        x += x & -x;
    }
}

int sum(int x)
{
    int ret = 0;
    while(x)
    {
        ret += a[x];
        x -= x & -x;
    }
    return ret;
}

int main()
{
    while(scanf("%d", &n), n)
    {
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i]), r[i] = i;
        sort(r + 1, r + n + 1, cmp); //离散化 用数排序后的下标代替数

        long long ans = 0;
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= n; ++i)
        {
            ans += sum(n) - sum(r[i]);
            add(r[i], 1);
        }
        printf("%lld\n", ans);
    }

    return 0;
}
//Last modified :   2015-07-31 10:20

