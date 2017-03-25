#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int nex[N], l;
char p[N];

void getNext()
{
	int i = 0, j = nex[0] = -1;
	while(i < l)
	{
		if(j == -1 || p[i] == p[j])
			nex[++i] = ++j;
		else j = nex[j];
	}
}

int main()
{
	while(~scanf("%s", p))
	{
		l = strlen(p);
		getNext();
		printf("%d\n", l - nex[l]);
	}
    return 0;
}
//Last modified :  2015-09-24 19:25 CST
