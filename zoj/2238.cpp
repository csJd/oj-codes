#include<cstdio>
#include<cstring>
using namespace std;
const int M = 1000010;
int cnt[M], cntt[M], ans[M];

int main()
{
    int n, m;
    while(scanf("%d", &n), n)
    {
        memset(ans, 0, sizeof(ans));
        memset(cnt, 0, sizeof(cnt));
        memset(cntt, 0, sizeof(cntt));
        for(int i = m = 1; i <= n; ++i) m *= 10;
        for(int i = n - 1; i < m + n - 1; ++i)
        {
            int t = 0;
            for(int j = i - n + 1; j < i; ++j)
                t = t * 10 + ans[j];
            for(int k = 0; k <= 9; ++k)
            {
                if(cntt[t] < 10 && cnt[t * 10 + k] == 0)
                {
                    ++cntt[t];
                    cnt[t * 10 + k] = 1;
                    ans[i] = k;
                    break;
                }
            }
        }
        for(int i = 0; i < m + n - 1; ++i)
            printf("%d", ans[i]);
    }
    return 0;
}
