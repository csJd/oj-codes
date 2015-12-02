#include <bits/stdc++.h>
using namespace std;
const int N = 1e9+1;

int main()
{
	char s[15];
	while(~scanf("%s",s))
	{
		int l = strlen(s);
		int p = 1, k = 1;
		while( k<l)
		{
			p+= 1<<k;
			++k;
		}
		int t = 0;
		for(int i=l-1; i>-1; --i)
			if(s[i]=='7') t+= 1<<(l-1-i);
		printf("%d\n", p+t);
	}

    return 0;
}
//Last modified :   2015-04-15 00:37
