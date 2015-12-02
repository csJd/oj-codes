#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const double eps = 1e-6;
double x[N], y[N], l[N], kx[N], ky[N];

int main()
{
    int cas = 0, n, m;
    while(~scanf("%d%d", &n, &m))
    {
        double len = x[0] = y[0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            scanf("%lf%lf", &x[i], &y[i]);
            l[i] = hypot(x[i] - x[i - 1], y[i] - y[i - 1]);
            kx[i] = (x[i] - x[i - 1]) / l[i];
            ky[i] = (y[i] - y[i - 1]) / l[i];
            len += l[i];
        }
        len = len / (m + 1);


        printf("Route %d\n", ++cas);

        for(int i = 0, j = 1; i < m; ++i)
        {
            double cur = len;
            while(cur > eps)
            {
                if(l[j] + eps >= cur)
                {
                    x[j - 1] += kx[j] * cur;
                    y[j - 1] += ky[j] * cur;
                    printf("CP%d: (%.3f, %.3f)\n", i + 1, x[j - 1], y[j - 1]);
                    l[j] -= cur;
                    cur = 0;
                }
                else cur -= l[j++];
            }
        }

    }
    return 0;
}
//Last modified :   2015-07-21 19:51

