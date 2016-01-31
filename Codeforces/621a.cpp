#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, min = 0, cnt =  0;
    long long sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &x);
        if(x % 2)
        {
            ++cnt;
            if(min == 0 ||  min >  x) min = x;
        }
        sum  += x;
    }
    if(cnt % 2) sum -= min;
    printf("%lld\n",  sum);

    return 0;
}
//Last modified :  2016-01-31 22:07 CST

