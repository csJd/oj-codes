#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int v[N];
int main()
{
	int v1,v2,t,d,k;
	while(~scanf("%d%d%d%d",&v1,&v2,&t,&d))
	{
		if(v1<v2) swap(v1,v2);
		v[0]=v1,v[n-1]=v2;
		int le=0,ri=n-1,ans = 0;
		while(le<ri-1)
		{
			if(v[le]>v[ri]) v[le+1] = v[le++]+d;
			else v[ri-1] = v[ri--] + d;
		}
		for(int i=0;i<n;++i) ans+=v[i];
		printf("%d\n",ans);
	}
    return 0;
}
//Last modified :   2015-04-13 00:27
