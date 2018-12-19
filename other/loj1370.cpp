#include <bits/stdc++.h>
using namespace std;
const int N = 2e6;
int pme[N >> 3], vis[N], m;

void getPrime()
{
    m = 0;
    for(int i = 2; i < N; ++i)
    {
        if(!vis[i]) pme[m++] = i;
        for(int j = 0; j < m; ++j)
        {
            if(pme[j] * i >= N) break;
            vis[pme[j] * i] = 1;
            if(i % pme[j] == 0) break;
        }
    }
}

int main()
{
    getPrime();
    int T, n, a, cas = 0;
    scanf("%d", &T);
    while(T--)
    {
        long long ans = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &a);
            int k = upper_bound(pme, pme + m, a) - pme;
            ans += pme[k];
        }
        printf("Case %d: %lld Xukha\n", ++cas, ans);
    }
    return 0;
}
//Last modified :  2015-10-09 20:15 CST

