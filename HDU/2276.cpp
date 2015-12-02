#include <cstdio>
#include <cstring>
using namespace std;
const int N = 105;
int n;

void matMul(char a[][N], char b[][N], char c[][N])
{
    char r[N][N] = {0};
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            for(int k = 0; k < n; ++k)
                r[i][j] ^= (a[i][k] & b[k][j]);
    memcpy(c, r, sizeof(r));
}

void matPow(char a[][N], int m)
{
    char r[N][N] = {0};
    for(int i = 0; i < n; ++i) r[i][i] = 1;
    while(m)
    {
        if(m & 1) matMul(r, a, r);
        matMul(a, a, a);
        m >>= 1;
    }
    memcpy(a, r, sizeof(r));
}

int main()
{
    int m;
    char s[N], ans[N];
    while(~scanf("%d%s", &m, s))
    {
        n = strlen(s);
        char a[N][N] = {0};
        for(int i = 0; i < n; ++i)
        {
            s[i] -= '0';
            int j = (i - 1 + n) % n;
            a[j][i] = a[i][i] = 1;
        }

        matPow(a, m);
        memset(ans, 0, sizeof(ans));
        for(int j = 0; j < n; ++j)
            for(int k = 0; k < n; ++k)
                ans[j] ^= (s[k] & a[k][j]);

        for(int i = 0; i < n; ++i)
            putchar(ans[i] ? '1' : '0');
        puts("");
    }
    return 0;
}
//Last modified :  2015-08-25 18:46 CST

