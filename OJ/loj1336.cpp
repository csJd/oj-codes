#include <cstdio>
using namespace std;
typedef long long ll;
int main()
{
	int T, cas;
	ll n, ans;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas)
	{
		ans = 0;
		scanf("%lld", &n);
		for(ll i = 1; i*i <=n; ++i)
		{
			++ans;
			if(i*i*2 <=n) ++ans;
		}
		printf("Case %d: %lld\n", cas,n - ans);
	}
    return 0;
}
//Last modified :   2015-08-06 09:21 CST
