#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
double pp[N];

int main()
{
    int n, p, l, r, pl, pr;
    double ans;
    while(~scanf("%d%d", &n, &p))
    {
        for(int i = 0; i < n; ++i)
        {
            pp[i] = 0;
            scanf("%d%d", &l, &r);
            pl = l, pr = r;
            if(l % p) pl = (l + p - l % p);
            if(r % p) pr = (r - r % p);
            if(pr >= pl) pp[i] = ((pr - pl) / p + 1) * 1.0 / (r - l + 1);
        }

        ans = pp[n - 1] + pp[0] - pp[n - 1] * pp[0];
        for(int i = 0; i < n - 1; ++i)
            ans +=  pp[i] + pp[i + 1]  - pp[i] * pp[i + 1];
        printf("%f\n", ans * 2000);
    }
    return 0;
}
//Last modified :  2016-01-31 22:41 CST

