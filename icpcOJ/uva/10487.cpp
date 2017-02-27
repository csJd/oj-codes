#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N];

int main()
{
    int cas = 0, n, m, q;
    while(scanf("%d", &n), n)
    {
        printf("Case %d:\n", ++cas);
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        sort(a, a + n);
        scanf("%d", &m);
        while(m--)
        {
            scanf("%d", &q);
            int ans = a[0] + a[1], t;
            for(int i = 0; i < n - 1; ++i)
            {
                int le = i + 1, ri = n - 1, lm, rm;
                while(le + 2 < ri)
                {
                    lm = (le + ri) >> 1;
                    rm = (lm + ri) >> 1;
                    if(abs(a[i] + a[lm] - q) < abs(a[i] + a[rm] - q)) ri = rm - 1;
                    else le = lm + 1;
                }
                for(int j = le; j <= ri; ++j)
                    if(abs(a[i] + a[j] - q) < abs(ans - q)) ans = a[i] + a[j];
            }
            printf("Closest sum to %d is %d.\n", q, ans);
        }
    }
    return 0;
}
//Last modified :  2015-08-17 11:03 CST

