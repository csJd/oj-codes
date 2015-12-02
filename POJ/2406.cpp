#include <cstdio>
#include <cstring>
using namespace std;
const int N =1000005;
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
	while(scanf("%s", p), s[0] != '.')
	{
		l = strlen(p);
		getNext();
		int ans = l % (l - nex[l]) ? 1 : l / (l - nex[l]);
		printf("%d\n", ans);
	}
    return 0;
}
//Last modified :  2015-09-24 19:37 CST
