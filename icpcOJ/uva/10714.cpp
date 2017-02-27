#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T, l, n;
	scanf("%d", &T);
	while(T--)
	{
		int a = 0, b = l, p;
		scanf("%d%d", &l, &n);
		while(n--)
		{
			scanf("%d", &p);
			a = max(a, min(p, l - p));
			b = max(b, max(p, l - p));
		}
		printf("%d %d\n",a, b);
	}
    return 0;
}
//Last modified :  2015-08-17 17:55 CST
