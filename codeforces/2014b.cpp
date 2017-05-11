#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 305;
int a[N], n, t;
char b[N][N];

void floyd()
{
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(b[i][k] == '1' && b[k][j] == '1') b[i][j] = '1';
}

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; ++i)
            scanf("%s", b[i] + 1);

        floyd();
        for(int i = 1; i <= n; ++i)
        {
            for(int j = i + 1; j <= n; ++j)
            {
                if(b[i][j] == '0') continue;
                if(a[i] > a[j]) swap(a[i], a[j]);
            }
        }

        for(int i = 1; i < n; ++i)
            printf("%d ", a[i]);
        printf("%d\n", a[n]);
    }
    return 0;
}

