#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
char s[N];
int p[N][N], d[N], n;
bool isPal(int l, int r)
{
    while(l < r)
        if(s[l++] != s[r--]) return 0;
    return 1;
}

int main()
{
    int cas;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%s", s);
        n = strlen(s);
        for(int i = 0; i < n; ++i)
            for(int j = i; j < n; ++j)
                p[i][j] = isPal(i, j);

        d[0] = 1;
        for(int i = 1; i < n; ++i)
        {
            d[i] = i + 1;
            if(p[0][i]) d[i] = 1;
            else for(int j = 0; j < i; ++j)
                if(p[j + 1][i]) d[i] = min(d[i], d[j] + 1);
        }
        printf("%d\n", d[n - 1]);
    }
    return 0;
}
