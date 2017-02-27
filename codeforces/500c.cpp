#include<cstdio>
#include<cstring>
using namespace std;
const int N = 505, M = 1005;
int a[N], b[M], s[N], v[N];
int main()
{
    int n, m, cnt, w, ans, p, t;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        for(int j = 1; j <= m; ++j)
            scanf("%d", &b[j]);

        cnt = 0;
        memset(v, 0, sizeof(v));
        for(int i = 1; i <= m && cnt < n; ++i)
        {
            t = b[i];
            if(!v[t]) s[cnt++] = t, v[t] = 1;
        }


        ans = 0;
        for(int i = 1; i <= m; ++i)
        {
            t = b[i], p = cnt - 1, w = 0;
            while(s[p] != t) w += a[s[p--]];
            while(p < cnt - 1) s[p] = s[p + 1];
            s[cnt - 1] = t;
            ans += w;
        }
        printf("%d\n", ans);

    }
    return 0;
}
