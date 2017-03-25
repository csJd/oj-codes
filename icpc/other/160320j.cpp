#include <cstdio>
#include <cstring>
using namespace std;
const int N = 15;
char g[N][N];
int x[] = {0, 0, -1, 1};
int y[] = { -1, 1, 0, 0};
int n;

bool ok(int r, int c, char k)
{
    for(int i = 0; i < 4; ++i)
    {
        if(r + x[i] < 0 || c + y[i] < 0 || r + x[i] >= n || c + y[i] >= n)
            continue;
        if(k == g[r + x[i]][c + y[i]]) return false;
    }
    return true;
}

int main()
{
    int T, cas = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%s", g[i]);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
            {
                if(g[i][j] == '.')
                {
                    for(char c = 'A'; c <= 'Z'; ++c)
                        if(ok(i, j, c))
                        {
                            g[i][j] = c;
                            break;
                        }
                }
            }

        printf("Case %d:\n", ++cas);
        for(int i = 0; i < n; ++i) puts(g[i]);
    }
    return 0;
}
