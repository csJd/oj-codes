#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1005;
int a[N], b[N], s[2*N];
int l, la, lb;
bool flag;

void dfs(int p, int i, int j)
{
	if(flag) return;
	if(p == la + lb)
	{
		flag = true;
		return;
	}
	if(a[i] == s[p]) dfs(p + 1, i + 1, j);
	if(b[i] == s[p]) dfs(p + 1, i, j + 1);
}

int main()
{
	
	while(scanf("%d%d", &la, &lb), la || lb)
	{
		for(int i = 0; i < la; ++i)
			scanf("%d", &a[i]);
		for(int i = 0; i < lb; ++i)
			scanf("%d", &b[i]);
		for(int i = 0; i < la + lb; ++i)
			scanf("%d", &s[i]);
		flag = false;
		dfs(0, 0, 0);
		if(!flag) printf("not ");
		puts("possible");
	}
    return 0;
}
//Last modified :  2015-08-13 12:43 CST
