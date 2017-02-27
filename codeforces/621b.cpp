#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int a[N], b[N];

int main()
{
    int n, x,  y;
    while(~scanf("%d", &n))
    {
        while(n--)
        {
            scanf("%d%d", &x, &y);
            ++a[x + y];
            ++b[x - y + 1001];
        }
        int sum = 0;
        for(int i = 1; i < 2001; ++i)
        {
            sum += (1 + a[i] - 1) * (a[i] - 1) / 2;
            sum += (1 + b[i] - 1) * (b[i] - 1) / 2;
        }
        printf("%d\n", sum);
    }
    return 0;
}
//Last modified :  2016-01-31 22:19 CST

