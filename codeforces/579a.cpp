#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a;
	while(~scanf("%d", &a))
	{
		int ans = 0;
		while(a)
		{
			if(a & 1) ++ans;
			a >>= 1;
		}
		printf("%d\n", ans);
	}

    return 0;
}
//Last modified :  2015-09-16 23:17 CST
