#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int a[N], b[N];

int main()
{
	int n, m , s;
	while(~scanf("%d%d", &n, &m))
	{
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		sort(a, a+n);
		for(int i = 0; i < m; ++i)
		{
			scanf("%d", &b[i]);
			s = upper_bound(a, a + n, b[i]) - a;
			printf("%d%c", s, i < m - 1?' ': '\n');
		}
	}
    return 0;
}
//Last modified :  2015-11-27 22:57 CST
