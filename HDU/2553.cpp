#include <bits/stdc++.h>
using namespace std;
const int N = 50;
int cnt, n, vis[3][N], ans[N];

void dfs(int r)
{
    if(r == n) ++cnt;
    for(int c = 0; r < n && c < n; ++c)
    {
        if(vis[0][c] || vis[1][r + c] || vis[2][r - c + n]) continue;
        vis[0][c] = vis[1][r + c] = vis[2][r - c + n] = 1;
        dfs(r + 1);
        vis[0][c] = vis[1][r + c] = vis[2][r - c + n] = 0;
    }
}

int main()
{
    for(int i = 1; i < 11; ++i)
    {
        n = i;
        dfs(cnt = 0);
        ans[i] = cnt;
    }
    while(scanf("%d", &n), n)
        printf("%d\n", ans[n]);
    return 0;
}
//Last modified :   2015-07-05 13:38
/*
1       1  <br>
2       0  <br>
3       0  <br>
4       2  <br>
5       10  <br>
6       4  <br>
7       40  <br>
8       92  <br>
9       352  <br>
10      724  <br>
11      2680  <br>
12      14200  <br>
13      73712  <br>
14      365596  <br>
15      2279184  <br>
16      14772512  <br>
17      95815104  <br>
18      666090624  <br>
19      4968057848  <br>
20      39029188884  <br>
21      314666222712  <br>
22      2691008701644  <br>
23      24233937684440  <br>
24      227514171973736  <br>
25      2207893435808352  <br>
*/
