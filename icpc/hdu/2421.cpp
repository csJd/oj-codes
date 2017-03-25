#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N  = 1020, MOD = 10007;
bool vis[N];
int pme[N], pn;

void initPrime()
{
    pn = 0;
    for(int i = 2; i < N; ++i)
    {
        if(!vis[i]) pme[pn++] = i;
        for(int j = 0; j < pn && i * pme[j] < N; ++j)
        {
            vis[i * pme[j]] = 1;
            if(i % pme[j] == 0) break;
        }
    }
}

int calc(int a, int b)
{
    int i = 0, ret = 1, cnt;
    while(pme[i] * pme[i] <= a)
    {
        cnt = 0;
        while(a % pme[i] == 0)
        {
            ++cnt;
            a /= pme[i];
        }
        cnt = (b * cnt + 1) % MOD;
        cnt = cnt * (cnt + 1) / 2 % MOD;
        ret = cnt * cnt % MOD * ret % MOD;
        ++i;
    }
    if(a > 1)
    {
        cnt = (b + 1) % MOD;
        cnt = cnt * (cnt + 1) / 2 % MOD;
        ret = cnt * cnt % MOD * ret % MOD;
    }
    return ret;
}

int main()
{
    int a, b, cas = 0;
    initPrime();
    while(~scanf("%d%d", &a, &b))
    {
        printf("Case %d: %d\n", ++cas, calc(a, b));
    }
    return 0;
}
//Last modified :  2015-08-27 20:23 CST

