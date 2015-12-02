#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	int cas,n,cnt, ans;
	char s[N];
	scanf("%d",&cas);
	for(int k=1;k<=cas;++k)
	{
		cnt = ans = 0;
		scanf("%d%s",&n,s);
		for(int i=0;s[i];++i)
		{
			if(cnt < i) ans+=i-cnt,cnt=i;
			cnt+=s[i]-'0';
		}
		printf("Case #%d: %d\n",k,ans);
	}
    return 0;
}
//Last modified :   2015-04-11 21:02
