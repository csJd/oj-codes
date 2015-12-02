#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
char s[N], s1[N], s2[N];

int main()
{
	int m, k, l, r;
	while(~scanf("%s", s + 1))
	{
		scanf("%d", &m);
		while(m--)
		{
			scanf("%d%d%d", &l, &r, &k);
			k = k % ( r - l + 1);
			strncpy(s1, s + l, r - l + 1 - k);
			strncpy(s2, s + r - k + 1,  k);
			strncpy(s + l, s2, k);
			strncpy(s + l + k, s1, r - l + 1 - k);
		//	puts(s + 1);
		}
		puts(s + 1);
	}
    return 0;
}
//Last modified :  2015-11-13 23:36 CST
