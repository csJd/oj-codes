#include <cstdio>
using namespace std;

int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		printf("2 %d %d\n", n, n);
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
				printf("%c", i > 25 ? i - 26 + 'a' : i + 'A');
			puts("");
		}

		puts("");
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
				printf("%c", j > 25? j - 26 + 'a' : j + 'A');
			puts("");
		}
	}
    return 0;
}
//Last modified :  2015-10-05 09:31 CST
