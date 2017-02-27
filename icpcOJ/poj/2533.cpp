#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1005;
int dp[N], a[N];

int main()
{
	int ans, n;
	while(~scanf("%d", &n))
	{
		ans = 0;
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
			dp[i] = 1;
			for(int j = 0; j < i; ++j)
				if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
    
    return 0;
}
//Last modified :  2015-09-15 19:45 CST
