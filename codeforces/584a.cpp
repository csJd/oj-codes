#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, t;
	while(~scanf("%d%d", &n,&t))
	{
		if(t == 10)
		{
			if(n == 1) puts("-1");
			else
			{
				printf("10");
				for(int i = 2; i < n; ++i)
					printf("0");
				puts("");
			}
		}
		else
		{
			printf("%d", t);
			for(int i = 1; i < n; ++i)
				printf("0");
			puts("");
		}
	}
    return 0;
}
//Last modified :  2015-10-07 00:27 CST

