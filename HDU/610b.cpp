#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char p[] = "anniversary";
	char s[200];
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s);
		int j = 0;
		for(int i = 0; s[i] && p[j]; ++i)
			if(s[i] == p[j]) ++j;
		puts(p[j]? "YES", "NO");
	}



    
    return 0;
}
//Last modified :   2015-07-25 19:11
