#include <cstdio>
#include <cstring>
using namespace std;
const int N = 400005;
int nex[N],ans[N],l;
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
		int n = 0;
		while(l)
		{
			ans[n++] = l;
			l = nex[l];
		}
		for(int i = n - 1; i >= 0; --i)
			printf("%d%c", ans[i], i ? ' ' : '\n');
	}
    return 0;
}
//Last modified :  2015-09-24 20:08 CST

