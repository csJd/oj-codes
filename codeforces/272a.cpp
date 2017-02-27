#include<cstdio>
using namespace std;
int main()
{
    int n,m,t;
    scanf("%d%d", &n, &m);
    t = n / 2;
    if(n < m) printf("-1\n");
    else
    {
        if(t * 2 != n) ++t;
        for(int i = t; i < 10001; ++i)
            if(i % m == 0)
            {
                printf("%d\n", i);
                break;
            }
    }
    return 0;
}
