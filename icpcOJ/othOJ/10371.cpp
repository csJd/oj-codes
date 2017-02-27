#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1000;
char s[N], op[N];
ll num[N];
int topo, topn;

ll calc1(char s[])
{
	char *p = s;
	ll t;
	

}

ll calc2(char s[])
{
	char *p = s;
}

int main()
{
	ll ans, ans1, ans2;
	while(~scanf("%s %lld", s, &ans))
	{
		int cnt = topo = topn = 0, len;
		char *p = s;
		while(*p)
		{
			sscanf(p, "%d%n", &num[topn++], &len);
			p += len;
			if(*p) sscanf("%c", &op[topo++]);
			++p;
		}

		for(int i = 0; i < topn; ++i)
			printf("%d\n", num[i]);

		for(int i = 0; i < topo; ++i)
			printf("%c\n", op[i]);

		ans1 = calc1();
		ans2 = calc2();
		if(ans == ans1) ++cnt;
		if(ans == ans2) ++cnt;

	}
    return 0;
}
//Last modified :  2015-10-15 18:14 CST
