#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int M = 1000010;
int pme[M], ner[M], m;
bool vis[M];

void initPrime()
{
    m = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = 2; i < M; ++i)
    {
        if(!vis[i]) pme[m++] = i;
        ner[i] = m;
        for(int j = 0; j < m && pme[j] * i < M; ++j)
        {
            vis[pme[j] * i] = 1;
            if(i % pme[j] == 0) break;
        }
    }
}

int main()
{
    initPrime();
    int T, n, a, cas = 0;
    long long ans;
    scanf("%d", &T);
    while(T--)
    {
        ans = 0;
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d", &a);
            ans += pme[ner[a]];
        }
        printf("Case %d: %lld Xukha\n", ++cas, ans);
    }

    return 0;
}
//Last modified :   2015-08-05 15:32

