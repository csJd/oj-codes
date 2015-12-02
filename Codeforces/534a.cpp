#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while(~scanf("%d",&))
	{
		if(n==1||n==2) puts("1\n1");
		else if(n==3) puts("2\n1 3");
		else if(n==4) puts("4\n3 1 4 2");
		else{
			for(int i=1;i<=n;++i) if(i%2) printf("%d ",i);
			for(int i=1;i<n-1;++i) if(i%2==0) printf("%d ",i);
			printf("%d\n",n%2?n-1:n);
		}
	}
    return 0;
}
//Last modified :   2015-04-13 00:00
