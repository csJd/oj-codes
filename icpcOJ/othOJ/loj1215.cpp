#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int T;
    ll a, b, l, c, d, m;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas)
    {
        printf("Case %d: ", cas);
        scanf("%lld%lld%lld", &a, &b, &l);
        m = a * b / gcd(a, b); //m为a,b的最大公约数

        if(l % m) puts("impossible");
        else
        {
            //要使lcm(c,m) = l  c中至少要有l中不在m中的素因子和l中指数大于m中的素因子取在l中的指数
            c = l / m;   //现在c中包含了l中不在m中的素因子取l中指数 和 l中指数大于m中的素因子取指数差
            //那么现在c还需要乘上c和m的公共素因子取m中的指数
            while((d = gcd(c, m)) != 1) //gcd(c,m) 取c,m公共素因子的小指数积
            {
                c = c * d, m = m / d;
                d = gcd(c, m);
            }
            printf("%lld\n", c);
        }
    }
    return 0;
}
