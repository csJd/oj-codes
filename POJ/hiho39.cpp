#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100005;
int a[N], t[N], n;
long long cnt;

void merge(int l, int m, int r)
{
    int pl = l, pr = m + 1, p = 0;
    while(pl <= m && pr <= r)
    {
        if(a[pl] <= a[pr]) t[p++] = a[pl++];
        else
        {
            t[p++] = a[pr++];
            cnt += m + 1 - pl;
        }
    }
    while(pl<=m) t[p++] = a[pl++];
    while(pr<=r) t[p++] = a[pr++];
    memcpy(a + l, t, sizeof(int)*p);
}

void mergeSort(int l, int r)
{
    if(l >= r) return;
    int	m = (l + r) >> 1;
    mergeSort(l, m);
    mergeSort(m + 1, r);
    merge(l, m, r);
}

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        cnt = 0;
        mergeSort(0, n - 1);
        printf("%lld\n", cnt);
    }
    return 0;
}
//Last modified :   2015-04-10 19:23
