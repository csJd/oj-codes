#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
char s[N], cd[300];

int main()
{
	char a, b;
	int n, m;
	while(~scanf("%d%d%s", &n,&m, s))
	{
		for(char c = 'a'; c <= 'z'; ++c)
			cd[c] = c;

		while(m--)
		{
			scanf(" %c %c", &a, &b);
			for(char c = 'a'; c <= 'z'; ++c)
			{
				if(cd[c] == a) cd[c] = b;
				else if(cd[c] == b) cd[c] = a;
			}
		}

		for(int i = 0; s[i]; ++i)
			s[i] = cd[s[i]];
		puts(s);

	}
    return 0;
}
//Last modified :  2015-10-25 17:10 CST
