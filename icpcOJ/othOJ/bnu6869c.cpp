#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T, n, m, q, x, cas = 0;
	scanf("%d", &T);
	while(T--)
	{
		printf("Case #%d:\n", ++cas);
		int f, r;
		scanf("%d%d%d", &n, &m, &q);
		if(n > m) swap(n, m);
		while(q--)
		{
			scanf("%d", &x);
			int le = 1, ri = n, mid;
			while(le <= ri)
			{
				mid = (le + ri) / 2;
				if(x - mid > m) le = mid + 1;
				else ri = mid - 1;
			}
			f = ri + 1;

			le = 1, ri = n;
			while(le <= ri)
			{
				mid = (le + ri) / 2;
				if(x - mid < 1) ri = mid - 1;
				else le = mid + 1;
			}
			r = le - 1;

			printf("%d\n", r - f + 1);
		}
	}
    return 0;
}
//Last modified :  2015-10-07 09:38 CST
