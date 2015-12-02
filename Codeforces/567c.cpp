#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int p[N];
int main()
{
	int n, m, k, a, t;
	scanf("%d%d%d%d",&n, &k, &a, &m);
	int ans = -1;
	for(int i = 1; i <=m; ++i)
	{
		scanf("%d", &t);
		if(ans > 0 && (t / (a+1) + (n-t) /(a+1) < k))
			ans = i;
	}
	printf("%d\n",ans);

    return 0;
}
//Last modified :   2015-08-06 01:38
