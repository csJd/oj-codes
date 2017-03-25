#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long ans;
	int T, cas = 0;
	int n, k;
	scanf("%d", &T);
	while(T--)
	{
		ans = 0;
		scanf("%d", &n);
		k = sqrt(n);
		for(int i = 1; i < k; ++i)
			ans += n/i;
		for(int j = n/k; j > 0; --j)
			ans += j * (n/j - n/(j+1));
		printf("Case %d: %lld\n", ++cas, ans);
	}
    return 0;
}
//Last modified :  2015-08-06 20:33 CST
