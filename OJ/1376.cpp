#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e6 + 5;
int s[N];

int main()
{
    int n, t, a, b, c, l, r;
    while(scanf("%d%d", &n, &t), n || t)
    {
        memset(s, 0, sizeof(s));
        double dt, x1, x2;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d%d%d", &a, &b, &c);
            dt = b * b - 4 * a * c;
            if(dt >= 0)
            {
                x1 = (-b + sqrt(dt)) / (a * 2);
                x2 = (-b - sqrt(dt)) / (a * 2);
            }

            if(a > 0)
            {
                if(dt <= 0) ++s[0], --s[t + 1];
                else
                {
                    l = x1, r = ceil(x2);
                    if(l >= 0 && l <= t) ++s[0], --s[l + 1];
                    if(r <= t && r >= 0) ++s[r], --s[t + 1];
                }
            }

            else  //a <= 0
            {
                l = 0, r = t;
                if(a < 0)
                {
                    if(dt > 0) continue;
                    l = max(0.0, ceil(x1)), r = min(double(t), x2);
                }

                else //a==0
                {
                    if(b > 0) l = max(0.0, ceil(-c * 1.0 / b));
                    else if(b < 0) r = min(double(t), floor(-c * 1.0 / b));
                    else if(c < 0) l = r = 0;
                }
                if(r > l) ++s[l], --s[r + 1];
            }
        }

        int ans = 0;
        for(int i = 1; i <= t; ++i)
        {
            s[i] += s[i - 1];
            if(s[i] == n && s[i-1] == n) ++ans;
        }

        if(ans >= t) puts("Cannot Stop");
        else if(ans > 0) printf("%d\n", ans);
        else puts("Unhappy");
    }

    return 0;
}
//Last modified :  2015-11-30 07:41 CST

