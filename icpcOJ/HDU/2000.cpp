#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s[5];
	while(~scanf("%s", s))
	{
		sort(s, s+3);
		printf("%c %c %c\n", s[0], s[1], s[2]);
	}
    return 0;
}
//Last modified :  2015-11-12 23:13 CST
