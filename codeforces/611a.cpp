#include <bits/stdc++.h>
using namespace std;
const int N = 105;

int main()
{
	char t[N], s[N];
	int n;
	while(~scanf("%d%s%s",&n, t, s))
	{
		if(s[0]  == 'w')
		{
			puts(n == 5 || n == 6 ? "53":"52");
		}
		else
		{
			if(n < 30) puts("12");
			else if(n == 30) puts("11");
			else puts("7");
		}
	}
    return 0;
}
//Last modified :  2015-12-30 23:05 CST
