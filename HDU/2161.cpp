#include <bits/stdc++.h>
using namespace std;
const int N = 16001;
int p[N], vis[N];

void getPrime()
{
	int cnt = 0;
	for(int i = 2; i < N; ++i)
	{
		if(!vis[i]) p[cnt++] = i;
		for(int j = 0; j<cnt && p[j] * i < N; ++j)
		{
			vis[p[j] * i] = 1;
			if(i % p[j] == 0) break;
		}
	}
}

int main()
{
    getPrime();
	vis[1] = vis[2] = 1;
	int cas = 0, n;
	while(scanf("%d", &n), n > 0)
	{
		printf("%d: %s\n", ++cas, vis[n]?"no":"yes");
	}
    return 0;
}
//Last modified :   2015-07-10 18:19
