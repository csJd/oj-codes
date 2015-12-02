#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int le[N], ri[N];
char s[M];

int main()
{
	char c[2];
	int p;
	scanf("%d%d%s", &n,&m,s+1);
	le[1] = ri[n] = 0;
	for(int i = 2; i < n; ++i)
		le[i] = s[i - 1] == '.' ? le[i-1] + 1 : 0; 
	for(int i = n - 1; i > 0; --i)
		ri[i] = s[i + 1] == '.' ? ri[i+1] + 1 : 0;

	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += ri[i], i += ri[i];
	

    return 0;
}
//Last modified :  2015-08-14 01:21 CST
