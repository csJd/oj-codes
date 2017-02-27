#include <cstdio>
using namespace std;

void modPow(int &s, int n, int k, int mod)
{
    while(k)
    {
        if(k & 1) s = s * n % mod;
        n = n * n % mod;
        k >>= 1;
    }
}

int main()
{
    int T, cas = 0, n, k, mod, s, t;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &k, &mod);
        for(int i = s = 0; i < n; ++i)
        {
            scanf("%d", &t);
            s = (s + t % mod) % mod;
        }
        s = k % mod * s % mod;
        modPow(s, n, k - 1, mod);
        printf("Case %d: %d\n", ++cas, s);
    }
    return 0;
}
//Last modified :  2015-08-07 14:07 CST
