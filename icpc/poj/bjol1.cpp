#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const double EPS = 1e-8;
double x[N], y[N], on[N];

int n, m;

int dis(int i, int j)
{
	return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - [j]) * (y[i] - y[j]);
}

int calc(int r)
{
	int ret = -1, val = -1;
	for(int i = 0; i < m; ++i)
	{
		int cnt = 0, flag = 0;;
		for(int j = 0; j < m; ++j)
		{
			if(fabs(dis(i, j) - r * r) < EPS) flag = 1;
			else if(dis(i, j) < r * r) ++cnt;
		}
		val = max(val, cnt);
		if(!flag) ret = max(ret, cnt);
	}
	return ret < 0 ? -val : ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &m, &n);
		for(int i = 0; i < m; ++i)
			scanf("%lf%lf", &x[i], &y[i]);

		int le = 0, ri = 3000, mid;
		while(le <= ri)
		{
			int mid = (le + ri) >> 1;
			if(abs(calc(mid)) >= n)
				ri = mid - 1;
			else le = mid + 1;
		}
		
		int r = ri + 1;
		while(r && calc(r) < 0) --r;
		printf("%d\n", calc(r) == n ? r : -1);
	}
    return 0;
}
//Last modified :  2015-09-20 12:58 CST
