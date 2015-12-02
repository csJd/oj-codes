#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
char s[N], p[N];
int nex[N];

int kmp()
{
	int ls = strlen(s), lp = strlen(p);
	int i = 0, j = nex[0] = -1;
	while(i < lp)
	{
		if(j == -1 || p[i] == p[j])
			nex[++i] = ++j;
		else j = nex[j];
	}

	int ret = i = j = 0;
	while(i < ls)
	{
		if(j == -1 || s[i] == p[j])
		{
			++i, ++j;
			if(j == lp)
			{
				++ret;
				j = 0;
			}
		}
		else j = nex[j];
	}

	return ret;
}

int main()
{
	while(scanf("%s", s))
	{
		if(s[0] == '#') break;
		scanf("%s", p);
		printf("%d\n", kmp());
	}
    return 0;
}
//Last modified :  2015-09-22 18:25 CST
