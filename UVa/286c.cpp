#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#define ZERO 301
using namespace std;
int n, m;
int mii[60005][605];
int a[60005];
int main(int argc, char const *argv[])
{
    while(~scanf("%d%d", &n, &m))
    {
        int x;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            a[x]++;
        }
        int ans = 0;
        mii[m][ZERO] = a[m] + 1;
        for (int i = m; i <= 30001; i++)
        {
            for (int j = max(1, m - 300); j < m + 300; j++)
            {
                if (!mii[i][j - m + ZERO])continue;
                mii[i + j][j - m + ZERO] = max(mii[i][j - m + ZERO] + a[i + j], mii[i + j][j - m + ZERO]);
                if (j - 1)
                    mii[i + j - 1][j - 1 - m + ZERO] = max(mii[i][j - m + ZERO] + a[i + j - 1], mii[i + j - 1][j - 1 - m + ZERO]);
                mii[i + j + 1][j + 1 - m + ZERO] = max(mii[i][j - m + ZERO] + a[i + j + 1], mii[i + j + 1][j + 1 - m + ZERO]);
                ans = max(ans, mii[i][j - m + ZERO]);

            }

        }
        printf("%d\n", ans - 1);
    }
    return 0;

}
