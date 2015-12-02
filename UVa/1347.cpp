#include <bits/stdc++.h>
#define l(x) (x[i]-x[j])*(x[i]-x[j])
using namespace std;
const int N = 105;
int x[N], y[N];
double d[N][N];

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d%d", &x[i], &y[i]);
            for(int j = 1; j < i; ++j)
                d[j][i] = sqrt(l(x) + l(y));
        }

        for(int i = 1; i < n - 1; ++i) d[n - 1][i] = d[n - 1][n] + d[i][n];
        for(int i = n - 2; i > 1; --i)
        {
            for(int j = 1; j < i; ++j)
                d[i][j] = min(d[i + 1][j] + d[i][i + 1], d[i + 1][i] + d[j][i + 1]);
        }
        printf("%.2lf\n", d[1][2] + d[2][1]);
    }
    return 0;
}
