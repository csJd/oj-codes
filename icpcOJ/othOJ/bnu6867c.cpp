#include <bits/stdc++.h>
using namespace std;
const int N = 1007;
double ave, a[N], s;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        s = 0;
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            scanf("%lf", &a[i]);
            s += a[i];
        }
        ave = s * 1.0 / n;
        for(int i = 0; i < n; ++i)
            if(a[i] > ave) ++ans;
        printf("%d\n", ans);
    }
    return 0;
}
//Last modified :  2015-10-04 12:09 CST

