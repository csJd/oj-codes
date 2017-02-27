#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int a[N];
int main()
{
    int n;
    while(~scanf("%d%d", &n, &a[0]))
    {
        int ans = 1, cnt = 1;
        for(int i = 1; i < n; ++i)
        {
            scanf("%d", &a[i]);
            if(a[i] >= a[i - 1]) ++cnt;
            else cnt = 1;
            if(cnt > ans) ans = cnt;
        }
        printf("%d\n", ans);
    }

    return 0;
}
//Last modified :  2015-09-23 00:31 CST

