#include <cstdio>
using namespace std;
const int N = 705;
int x[N], y[N];

bool aLine(int i, int j, int k)
{
    return (x[i] - x[j]) * (y[j] - y[k]) == (x[j] - x[k]) * (y[i] - y[j]);
}

int main()
{
    int n;
    while(scanf("%d", &n), n)
    {
        for(int i = 0; i < n; ++i)
            scanf("%d%d", &x[i], &y[i]);

        int ans = n < 2 ? n : 2;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                int cnt = 2;
                for(int k = j + 1; k < n; ++k)
                    if(aLine(i, j, k)) ++cnt;
                if(cnt > ans) ans = cnt;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
//Last modified :  2015-08-17 20:24 CST

