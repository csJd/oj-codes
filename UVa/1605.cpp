#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, cas = 0;
    while(~scanf("%d", &n))
    {
        if(cas++) puts("");
        printf("2 %d %d\n", n, n);
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
                if(i > 25) putchar('a' + i - 26);
                else putchar('A' + i);
            puts("");
        }
        puts("");
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
                if(j > 25) putchar('a' + j - 26);
                else putchar('A' + j);
            puts("");
        }
    }
    return 0;
}
