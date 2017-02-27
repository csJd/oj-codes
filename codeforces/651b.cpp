#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N];

int main()
{
    int n, t;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        int ans = 0;
        sort(a, a + n);
        while(n > 0 && a[0] != a[n - 1])
        {
            int cnt = 0;
            for(int i = 1; i < n; ++i)
            {
                if(a[i] > a[i - 1]) ++ans;
                else a[cnt++] = a[i];
            }
            n = cnt;
        }
        printf("%d\n", ans);
    }

    return 0;
}
//Last modified :  2016-03-07 17:33 CST

