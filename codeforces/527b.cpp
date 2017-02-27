#include <bits/stdc++.h>
using namespace std;
const int N = 200005, M = 26;
char a[N], b[N];
int p[M][M];
int main()
{
    int n, d, u, v, flag;
    while(~scanf("%d", &n))
    {
        memset(p, 0, sizeof(p));
        scanf("%s%s", a, b);
        for(int i = d = flag = 0; i < n; ++i)
            if(a[i] != b[i]) ++d, p[a[i] - 'a'][b[i] - 'a'] = i + 1;

        for(int i = 0; i < M; ++i)
            for(int j = 0; j < M; ++j)
                if((u = p[i][j]) && (v = p[j][i])) flag = 2, i = j = M;

        if(!flag) for(int i = 0; i < M; ++i) for(int j = 0; j < M; ++j) for(int k = 0; k < M; ++k)
                      if((u = p[i][j]) && (v = p[j][k])) flag = 1, i = j = k = M;
        if(!flag) u = v = -1;

        printf("%d\n%d %d\n", d - flag, u, v);
    }
    return 0;
}

