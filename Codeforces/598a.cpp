#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int t;
	ll n, ans, k, minu;
	scanf("%d", &t);
	while(t--)
	{
		k = 1;
		minu = 0;
		scanf("%lld", &n);
		ans = n * (n + 1) / 2;
		while(k <= n)
		{
			minu += k;
			k <<= 1;
		}
		printf("%lld\n", ans - minu*2);
	}
    return 0;
}
//Last modified :  2015-11-13 23:05 CST
