#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, a;
	while(~scanf("%d",&n))
	{
		int flag = 1;
		while(n--)
		{
			scanf("%d",&a);
			if(a==1) flag = -1;
		}
		printf("%d\n", flag);
	}

    
    return 0;
}
//Last modified :   2015-07-22 22:11
