#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;
const int N = 1005;
int a[N][N], b[N][N], t[N][N];

int readint()
{
    char c = 0;
    int ret = 0;
    while(!isdigit(c)) c = getchar();
    while(isdigit(c))
    {
        ret = ret*10 + c-'0';
        c = getchar();
    }
    return ret;
}

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                a[i][j] = readint(), a[i][j] %= 3;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                b[i][j] = readint(), b[i][j] %= 3;

        memset(t, 0, sizeof(t));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                for(int k = 0; k < n; ++k)
                    t[i][j] = (t[i][j] + a[i][k] * b[k][j]) % 3;

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
                printf("%d%c", t[i][j], j == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}


