#include <cstdio>
#include <cstring>
using namespace std;
const int N = 50, M = 1005;
bool dp[N][M];
int main()
{
	int n,b,m,t;
	while(~scanf("%d%d%d",&n,&b,&m))
	{
		memset(dp,0,sizeof(dp));
		dp[0][b] = 1;
		for(int i = 1; i<=n; ++i)
		{
			scanf("%d",&t);
			for(int j = 0; j <= m; ++j)
				dp[i][j] = (j-t>=0 && dp[i-1][j-t]) || (j+t)<=m && dp[i-1][j+t];
		}
		while(m && !dp[n][m]) --m;
		printf("%d\n",dp[n][m]? m : -1);
	}
    return 0;
}
//Last modified :   2015-06-14 08:01
