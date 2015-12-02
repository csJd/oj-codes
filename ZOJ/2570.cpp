#include<cstdio>
#include<cstring>
using namespace std;
const int N = 205;
int d[N][N], n;

void floyd()
{
    for(int k = 1; k <= n; ++k)
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
        d[i][j] |= (d[i][k] & d[k][j]);

}

int main()
{
    int a, b;
    char s[30];
    while(scanf("%d", &n), n)
    {
        memset(d, 0, sizeof(d));
        while(scanf("%d%d", &a, &b), a)
        {
            scanf("%s", s);
            for(int i = 0; s[i] != '\0'; ++i)
                d[a][b] = d[a][b] | (1 << s[i] - 'a');
        }
        floyd();
        while(scanf("%d%d", &a, &b), a)
        {
            for(char c = 'a'; c <= 'z'; ++c)
                if(d[a][b] & (1 << c - 'a')) printf("%c", c);
            if(d[a][b] == 0) printf("-");
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

