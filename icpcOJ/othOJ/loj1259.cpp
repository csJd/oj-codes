#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+5, M = 1e6+5;
int p[M];
bool v[N];
void initPrime()
{
	int cnt = 0;
	v[0] = v[1] = 1;
	for(int i = 2; i < N; ++i)
	{
		if(!v[i]) p[cnt++] = i;
		for(int j = 0; j < cnt && i * p[j] < N; ++j)
		{
			v[i*p[j]] = 1;
			if(i%p[j] == 0) break;
		}
	}
}

int main()
{
	initPrime();
	int T, n, ans;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas)
	{
		scanf("%d", &n);
		ans = 0;
		for(int i = 0; p[i] <= n/2; ++i)
		{
			if(!v[n - p[i]]) ++ans;
		}
		printf("Case %d: %d\n", cas, ans);
	}
    return 0;
}
//Last modified :   2015-07-10 19:14
