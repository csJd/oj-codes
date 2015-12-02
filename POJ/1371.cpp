#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int a, b, c, cas;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d%d%d", &a, &b, &c);
        if(a > b) swap(a, b);
        if(a > c) swap(a, c);
        if(b > c) swap(b, c);
        printf("%d\n", b + c);
    }
    return 0;
}
