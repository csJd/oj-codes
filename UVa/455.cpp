#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100;
char s[N];
int l;

bool isPeriod(int p)
{
    if(l % p) return false;
    for(int i = 0; i < p; ++i)
    {
        for(int j = 0; j * p + i < l; ++j)
            if(s[j * p + i] != s[i]) return false;
    }
    return true;
}

int main()
{
    int n, cas;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%s", s);
        l = strlen(s);
        for(int i = 1; i <= l; ++i)
        {
            if(isPeriod(i))
            {
                printf("%d\n", i);
                break;
            }
        }
        if(cas) printf("\n");
    }
    return 0;
}
