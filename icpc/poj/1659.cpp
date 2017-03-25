#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 20;
int mat[N][N], ord[N];

bool cmp(int i, int j)
{
    return mat[i][0] > mat[j][0];
}

int main()
{
    int cas, i, j, k, t, n;
    scanf("%d", &cas);
    while(cas--)
    {

        memset(mat, 0, sizeof(mat));
        scanf("%d", &n);
        for(i = 1; i <= n; ++i)
        {
            scanf("%d", &mat[i][0]);
            ord[i] = i;
        }

        for(i = 1; i <= n; ++i)
        {
            sort(ord + i, ord + n + 1, cmp);
            t = ord[i];
            if(mat[t][0] < 0) break;
            for(j = 1; j <= mat[t][0]; ++j)
            {
                k = ord[i + j];
                mat[t][k] = mat[k][t] = 1;
                --mat[k][0];
            }
        }

        if(i <= n) printf("NO\n");
        else
        {
            printf("YES\n");
            for(i = 1; i <= n; ++i)
            {
                for(int j = 1; j <= n; ++j)
                    printf("%d ", mat[i][j]);
                printf("\n");
            }
        }
        if(cas) printf("\n");
    }
    return 0;
}
