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
	int T = 0;
	while(scanf("%d", &l), l)
	{
		scanf("%s", p);
		getNext();
		printf("Test case #%d\n",++T); 
		for(int i = 1; i <= l; ++i)
		{
			int j = i - nex[i];
			if(i % j == 0 && i / j > 1)
				printf("%d %d\n", i, i / j);
		}
		puts("");
	}
    return 0;
}
//Last modified :  2015-09-24 19:09 CST
