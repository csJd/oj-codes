#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N], b[N];

int main()
{
    int na, nb, k, m;
    while(~scanf("%d%d", &na, &nb))
    {
        scanf("%d%d", &k, &m);

        for(int i = 0; i < na; ++i)
            scanf("%d", &a[i]);

        for(int i = 0; i < nb; ++i)
            scanf("%d", &b[i]);

        puts( a[k-1] < b[nb - m] ? "YES" : "NO");

    }
    return 0;
}
//Last modified :  2015-08-23 00:34 CST

