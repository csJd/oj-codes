#include <bits/stdc++.h>
using namespace std;
const int N = 105;

bool isSub(char p[], char s[])
{
    int i = 0, j = 0;
    while(p[i] && s[j])
    {
        if(p[i] == s[j]) ++i;
        ++j;
    }
    return p[i] == 0;
}

int main()
{
    char s[N];
    while(~scanf("%s", s))
    {
        int k = 0;
        while(k < 20000)
        {
            char p[N] = {0};
            sprintf(p, "%d", k);
            if(isSub(p, s))
            {
                printf("YES\n%s\n", p);
                break;
            }
            k += 8;
        }
        if(k >= 20000) puts("NO");
    }

    return 0;
}
//Last modified :   2015-06-05 00:56

