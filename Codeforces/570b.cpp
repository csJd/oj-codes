#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, ans;
	while(~scanf("%d%d", &n ,&m))
	{
		if(m < (n + 1)/2) ans = m + 1;
		else  ans = m - 1;
	}
    return 0;
}
//Last modified :  2015-08-14 00:58 CST
