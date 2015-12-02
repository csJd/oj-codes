#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int a[N], n;

bool zeros()
{
    for(int i = 0; i < n; ++i)
        if(a[i]) return 0;
    return 1;
}

int main()
{
    int cas, i, k, t;
    scanf("%d", &cas);
    while (cas--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; ++i) scanf("%d", &a[i]);
        for(k = 0; k < 1000 && !zeros(); ++k)
        {
            t = a[n - 1] - a[0];
            for(i = 0; i < n - 1; ++i)
                a[i] = abs(a[i] - a[i + 1]);
            a[n - 1] = t;
        }
        if(k < 1000) puts("ZERO");
        else puts("LOOP");
    }
    return 0;
}
