#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long a[N];
int main()
{
	int n;
	long long mi, ma;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%lld", &a[i]);
	for(int i = 0; i < n; ++i)
	{
		if(!i) mi = a[1] - a[0], ma = a[n-1] - a[0];
		else if(i == n-1) mi = a[i] - a[i-1], ma = a[i] - a[0];
		else mi = min(a[i] - a[i-1], a[i+1] - a[i]), ma = max(a[i] - a[0], a[n-1] - a[i]);
		printf("%lld %lld\n", mi, ma);
	}		
    return 0;
}
//Last modified :   2015-08-06 00:04
