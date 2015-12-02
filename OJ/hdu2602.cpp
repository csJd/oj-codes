#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int c[N],v[N],d[N];

int main()
{
	int T, n, s;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&s);
		for(int i = 0; i<n; ++i)
			scanf("%d", &v[i]);
		for(int i = 0; i<n; ++i)
			scanf("%d", &c[i]);
		memset(d, 0, sizeof(d));
		for(int i = 0; i < n; ++i)
			for(int j = s; j >= c[i]; --j)
				d[j] = max(d[j], d[j - c[i]] + v[i]);
		printf("%d\n",d[s]);
	}
    return 0;
}
//Last modified :   2015-06-13 11:01

