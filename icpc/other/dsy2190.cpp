#include <bits/stdc++.h>
using namespace std;
const int N = 4e4+5;
int p[N], phi[N]; 

void getPhi()
{
	int cnt = 0;
	for(int i = 2; i < N; ++i)
	{
		if(!phi[i]) p[cnt++] = i, phi[i] = i-1;
		for(int j = 0; j < cnt && p[j] * i < N; ++j)
		{
			if(i % p[j] == 0) 
			{
				phi[i * p[j]] = phi[i] * p[j];
				break;
			}
			else phi[i * p[j]] = phi[i] * (p[j] - 1);
		}
	}
}

int main()
{
	getPhi();
	phi[1] = 1;
	int n;
	while(~scanf("%d",&n))
	{
		int ans = 0;
		for(int i = 1; i < n; ++i)
			ans += 2 * phi[i];
		printf("%d\n", ans + 1);
	}
    return 0;
}
//Last modified :   2015-07-13 08:09
