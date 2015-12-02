#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
char s[N], t[N];
int main()
{
	while(~scanf("%s%s", s, t))
	{
		int i = 0, j = 0;
		while(s[i] && t[j])
		{
			if(s[i] == t[j])
				++i, ++j;
			else ++j;
		}
		puts(s[i] ? "No" : "Yes");
	}
    return 0;
}
//Last modified :  2015-08-17 14:57 CST
