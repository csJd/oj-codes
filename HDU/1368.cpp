#include<cstdio>
using namespace std;
const int N = 1005;
int n, m, cnt[N], sum;
char s[N][N], ans[N];
int main()
{
    int cas;
    while(~scanf("%d", &cas))
    {
        while(cas--)
        {
            scanf("%d%d", &n, &m);
            sum = ans[m] =0;
            for(int i = 0; i < n; ++i)
                scanf("%s", s[i]);
            for(int j = 0; j < m; ++j)
            {
                cnt['A'] = cnt['G'] = cnt['C'] = cnt['T'] = 0;
                for(int i = 0; i < n; ++i) ++cnt[s[i][j]];
                ans[j] = 'A';
                if(cnt['C'] > cnt[ans[j]]) ans[j] = 'C';
                if(cnt['G'] > cnt[ans[j]]) ans[j] = 'G';
                if(cnt['T'] > cnt[ans[j]]) ans[j] = 'T';
                sum += (n - cnt[ans[j]]);
            }
            printf("%s\n%d\n", ans, sum);
        }
    }

    return 0;
}
