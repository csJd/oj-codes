#include <cstdio>
using namespace std;

int main()
{
	int n;
	char s[10005];
	while(gets(s) != NULL)
	{
		if(!s[0]) continue;
		n = strlen(s);
		for(int i = 0; i+2 < n; ++i)
		{
			if(s[i] == 'c' && s[i+1] == 'c' && s[i+2] == 'Q')
				s[++i] = 'x', s[++i] ='w';
		}
		puts(s);
	}
    return 0;
}
//Last modified :  2015-08-11 12:07 CST
