#include <cstdio>
using namespace std;
const int N = 1005;
char s[N];

bool cmp(int i, int j)
{
	if(s[i] == s[j]) return i < j;
	return s[i] > s[j];
}

int main()
{
	int T, n, k;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s%d", s, &k);
		n = strlen(s);
		for(int i = 0;i < n;++i)
			r[i] = i;
		sort(r, r+n, cmp);
		for(int i = 0; i < k; ++i)
			s[i] = 0;
		bool isfirst = 1;
		for(int i = 0; i < n; ++i)
		{
			if(!s[i]) continue;
			if(s[i] == '0' && isfirst)
			{
				isfirst = 0;
				continue;
			}
			putchar(s[i]);
		}
		puts("");
	}
    return 0;
}
//Last modified :  2015-08-11 12:33 CST
