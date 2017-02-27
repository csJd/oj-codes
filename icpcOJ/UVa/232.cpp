#include <cstdio>
#include <cstring>
using namespace std;
int n, m, tmp;
const int N = 1000;
char puz[N][N], num[N][N];

int type(int i, int j)
{
    int ret = 0;
    if(puz[i][j] == '*') return 0;
    if(i == 1 || puz[i - 1][j] == '*') ret += 2;
    if(j == 1 || puz[i][j - 1] == '*') ++ret;
    return ret;
}

int main()
{
    int cas = 0, cnt;
    while(scanf("%d", &n), n)
    {
        scanf("%d", &m);
        for(int i = 1; i <= n; ++i)
            scanf("%s", puz[i] + 1);
        cnt = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                num[i][j] = (type(i, j) ? (++cnt) : 0);




        if(cas++) puts("");
        printf("puzzle #%d:\nAcross\n", cas);
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                tmp = type(i, j);
                if(tmp != 1 && tmp != 3) continue;
                printf("%3d.", num[i][j]);
                while(puz[i][j] != '*' && j <= m)  putchar(puz[i][j++]);
                printf("\n");
            }
        }

        puts("Down");
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                tmp = type(i, j);
                int t = i;
                if(tmp != 2 && tmp != 3) continue;
                printf("%3d.", num[i][j]);
                while(puz[t][j] != '*' && t <= n)  putchar(puz[t++][j]);
                puts("");
            }
        }
    }
    return 0;
}
