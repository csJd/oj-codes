#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int cas, x, n;
    char s[5];
    scanf("%d", &cas);
    while(cas--)
    {
        x = 0;
        scanf("%d", &n);
        while(n--)
        {
            scanf("%s", s);
            if(s[0] == '+' || s[1] == '+') ++x;
            else --x;
        }
        printf("%d\n", x);
    }
    return 0;
}
