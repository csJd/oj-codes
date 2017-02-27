#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int d[N][N], v[N], c[N];
int main()
{
    int cas, n, m;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i) scanf("%d", &v[i]);
        for(int i = 0; i < n; ++i) scanf("%d", &c[i]);
        memset(d, 0, sizeof(d));
        //d[i][j]表示前i个骨头用容量为j的包装能得到的最大价值
        for(int i = 1; i < n; ++i)
            for(int j = m; j >= c[i]; --j)
                d[i][j] = max(d[i - 1][j], d[i - 1][j - c[i]] + v[i]);
        printf("%d\n", d[n - 1][m]);
    }
    return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//const int N = 1005;
//int d[N], v[N], c[N];
//int main()
//{
//    int cas, n, m;
//    scanf("%d", &cas);
//    while(cas--)
//    {
//        scanf("%d%d", &n, &m);
//        for(int i = 0; i < n; ++i) scanf("%d", &v[i]);
//        for(int i = 0; i < n; ++i) scanf("%d", &c[i]);
//        memset(d, 0, sizeof(d));
//        for(int i = 0; i < n; ++i)
//            for(int j = m; j >= c[i]; --j)
//                d[j] = max(d[j], d[j - c[i]] + v[i]);
//        printf("%d\n",d[m]);
//    }
//    return 0;
//}
