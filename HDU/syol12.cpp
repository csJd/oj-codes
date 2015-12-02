#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5000005;
int t[N];

int main()
{
    int T, cas = 0, n, a, b;
    scanf("%d", &T);
    ll x, y;
    while(T--)
    {
        scanf("%d%d%d", &n, &a, &b);
        for(int i = 0; i < n; ++i)
            scanf("%d", &t[i]);
        sort(t, t + n);
        int amax = 0, amin = 0;
        for(int i = 0; i < n; ++i)
        {
            if(abs(t[i]) > abs(t[amax])) amax = i;
            if(abs(t[i]) < abs(t[amin])) amin = i;
        }

        if( a < 0 && b < 0)
        {
            x = t[amin];
            y = amin == 0 ? t[1] : t[0];
        }

        else if(a < 0 && b == 0)
        {
            x = t[amin];
            y = 0;
        }

        else if(a < 0 && b > 0)
        {
            x = t[amin];
            y = amin == n - 1 ? t[n - 2] : t[n - 1];
        }

        else if(a == 0 && b < 0)
        {
            x = 0;
            y = t[0];
        }

        else if(a == 0 && b == 0)
        {
            x = y = 0;
        }

        else if(a == 0 && b > 0)
        {
            x = 0 ;
            y = t[n - 1];
        }

        else if(a > 0 && b < 0)
        {
            x = t[amax];
            y = amax == 0 ? t[1] : t[0];
        }

        else if(a > 0 && b == 0)
        {
            x = t[amax];
            y = 0;
        }

        else
        {
            x = t[amax];
            y = amax == n - 1 ? t[n - 2] : t[n - 1];
        }

        printf("Case #%d: %I64d\n", ++cas,  x * x * a + y * b);
    }
    return 0;
}
//Last modified :  2015-09-19 13:23 CST

