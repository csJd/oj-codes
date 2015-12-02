#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
bool inq[N];

int main()
{
	int n, ans, a, t, in;
	char s[5];
	scanf("%d", &n);
	while(n--)
	{
		ans = t = in = 0;
		scanf("%s%d",s, &a);
		if(s[0] == '+')
		{
			inq[a] = 1;
			++in;
			if(ans < in) ans = in;
		}
		else
		{
			if(inq[a])
			{
				inq[a] = 0;
				--in;
			}
			else
			{
				++ans;
			}
		}
	}
	printf("%d\n", ans);
    
    return 0;
}
//Last modified :   2015-08-06 00:19
