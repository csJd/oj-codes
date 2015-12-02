#include <bits/stdc++.h>
using namespace std;
const int N = 35;
typedef long long ll;
ll dp[N][N];

int main()
{
	int T, cas = 0;
	int n, m;
	scanf("%d", &T);
	while(T--)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%d%d", &n, &m);
		dp[1][1] = 1;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				dp[i+1][j] += dp[i][j], dp[i][j+1] += dp[i][j];
		printf("%lld\n", dp[n][m]);
	}
    return 0;
}
//Last modified :  2015-09-27 16:24 CST
